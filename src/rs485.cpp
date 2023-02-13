/**
 *  @file       rs485.cpp
 */

#include <cstring>
#include "rs485.hpp"

namespace rs485
{
    Rs485::Rs485() :
        m_Interface(nullptr),
        m_logic{TXS_IDLE,}
    {
    }

    bool Rs485::transportInit(rs485Interface_t* ptrInterface)
    {
        assert_param(ptrInterface != NULL);
        assert_param(ptrInterface->usart != NULL);
        assert_param(ptrInterface->ptrBuffTx != NULL);
        assert_param(ptrInterface->ptrBuffRx != NULL);
        assert_param(ptrInterface->buffTxSize > 0);
        assert_param(ptrInterface->buffRxSize > 0);

        if (m_Interface != nullptr) {
            transportDeinit();
        }

        m_Interface = ptrInterface;
        restart();

        return true;
    }

    bool Rs485::transportDeinit()
    {
        if (m_Interface == nullptr) {
            return false;
        }

        LL_TIM_DisableCounter(m_Interface->timer);
        LL_TIM_DisableIT_UPDATE(m_Interface->timer);
        LL_TIM_ClearFlag_UPDATE(m_Interface->timer);

        LL_USART_Disable(m_Interface->usart);
        LL_USART_DisableIT_RXNE(m_Interface->usart);
        LL_USART_DisableIT_ERROR(m_Interface->usart);
        LL_USART_DisableIT_TXE(m_Interface->usart);
        LL_USART_DisableIT_TC(m_Interface->usart);

        return true;
    }

    bool Rs485::transportReset()
    {
        if (!transportDeinit()) {
            return false;
        }
        restart();
        return true;
    }

    bool Rs485::sendData(const uint8_t* ptrData, uint32_t len)
    {
        if (m_Interface == nullptr) {
            return false;
        }
        if (ptrData == NULL ||
            len == 0 ||
            len > m_Interface->buffTxSize)
        {
            return false;
        }
        if (m_logic.txState != TXS_IDLE)
        {
            return false;
        }
        if (m_logic.isRxEn) {
            m_logic.isRxEn = false;
            LL_TIM_DisableCounter(m_Interface->timer);
            LL_TIM_ClearFlag_UPDATE(m_Interface->timer);
        }

        m_logic.txState = TXS_RUN;

        std::memcpy(m_Interface->ptrBuffTx, ptrData, len);
        m_logic.txLen   = len;
        m_logic.txCount = 0;

        HAL_GPIO_WritePin(  m_Interface->dirPort,
                            m_Interface->dirPin,
                            GPIO_PIN_SET);
        LL_USART_TransmitData8( m_Interface->usart,
                                m_Interface->ptrBuffTx[m_logic.txCount++]);
        LL_USART_EnableIT_TXE(m_Interface->usart);

        return true;
    }

    bool Rs485::getData(uint8_t* ptrData, uint32_t* lenInOut)
    {
        if (m_Interface == nullptr) {
            return false;
        }
        if (ptrData == NULL || lenInOut == NULL)
        {
            return false;
        }
        if (!m_logic.isRxReady)
        {
            return false;
        }
        if (*lenInOut < m_logic.rxLen)
        {
            return false;
        }

        std::memcpy(ptrData, m_Interface->ptrBuffRx, m_logic.rxLen);
        *lenInOut = m_logic.rxLen;
        m_logic.isRxReady = false;

        return true;
    }

    void Rs485::timerHandler()
    {
        assert_param(m_Interface != nullptr);

        if (m_logic.txState == TXS_SYNC) {
            m_logic.txState = TXS_IDLE;
        }

        if (m_logic.isRxEn) {
            m_logic.isRxEn     = false;
            m_logic.isRxReady  = true;
        }
    }

    void Rs485::rxneHandler()
    {
        assert_param(m_Interface != nullptr);

        if (m_logic.isRxReady) {
            uint8_t none = LL_USART_ReceiveData8(m_Interface->usart);
            m_logic.errCount++;
            return;
        }

        if (m_logic.isRxEn) {
            LL_TIM_SetCounter(m_Interface->timer, m_Interface->timeSyncRx);

            if (m_logic.rxLen >= m_Interface->buffRxSize) {
                uint8_t none = LL_USART_ReceiveData8(m_Interface->usart);
                m_logic.isRxReady  = true;
                m_logic.isRxEn     = false;
                m_logic.errCount++;
                return;
            }

            m_Interface->ptrBuffRx[m_logic.rxLen++] =
                LL_USART_ReceiveData8(m_Interface->usart);
            return;
        }

        m_logic.rxLen      = 0;
        m_Interface->ptrBuffRx[m_logic.rxLen++] = 
            LL_USART_ReceiveData8(m_Interface->usart);
        LL_TIM_SetCounter(m_Interface->timer, m_Interface->timeSyncRx);
        LL_TIM_EnableCounter(m_Interface->timer);

        m_logic.isRxEn = true;
    }

    void Rs485::tcHandler()
    {
        assert_param(m_Interface != nullptr);

        LL_USART_DisableIT_TC(m_Interface->usart);
        if (m_logic.txState != TXS_RUN)
        {
            return;
        }

        HAL_GPIO_WritePin(  m_Interface->dirPort,
                            m_Interface->dirPin,
                            GPIO_PIN_RESET);

        LL_TIM_SetCounter(m_Interface->timer, m_Interface->timeSyncTx);
        LL_TIM_EnableCounter(m_Interface->timer);
        m_logic.txState = TXS_SYNC;
    }

    void Rs485::txeHandler()
    {
        assert_param(m_Interface != nullptr);

        if (m_logic.txState != TXS_RUN)
        {
            LL_USART_DisableIT_TXE(m_Interface->usart);
            return;
        }

        if (m_logic.txCount < m_logic.txLen)
        {
            LL_USART_TransmitData8(m_Interface->usart,
                m_Interface->ptrBuffTx[m_logic.txCount++]);
            return;
        }

        LL_USART_DisableIT_TXE(m_Interface->usart);
        LL_USART_EnableIT_TC(m_Interface->usart);
    }

    void Rs485::errHandler()
    {
        assert_param(m_Interface != nullptr);

        m_logic.errCount++;
    }

    void Rs485::restart()
    {
        m_logic.txState     = TXS_IDLE;
        m_logic.rxLen       = 0;
        m_logic.isRxEn      = false;
        m_logic.isRxReady   = false;

        HAL_GPIO_WritePin(  m_Interface->dirPort,
                            m_Interface->dirPin,
                            GPIO_PIN_RESET);
        LL_USART_ClearFlag_FE(m_Interface->usart);
        LL_USART_ClearFlag_NE(m_Interface->usart);
        LL_USART_ClearFlag_ORE(m_Interface->usart);
        
        LL_USART_EnableIT_RXNE(m_Interface->usart);
        LL_TIM_ClearFlag_UPDATE(m_Interface->timer);
        LL_TIM_EnableIT_UPDATE(m_Interface->timer);
        //LL_USART_EnableIT_ERROR(m_Interface->usart);
    }
}
