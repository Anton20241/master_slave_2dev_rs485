/**
 *  @file       rs485.hpp
 *  @brief
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#pragma once

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i_transport.hpp"

namespace rs485
{
/* Exported defines ----------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
    typedef struct
    {
        USART_TypeDef*      usart;
        TIM_TypeDef *       timer;
        GPIO_TypeDef*       dirPort;
        uint16_t            dirPin;
        const uint32_t      timeSyncRx;
        const uint32_t      timeSyncTx;
        const uint16_t      buffTxSize;
        const uint16_t      buffRxSize;
        uint8_t*            ptrBuffTx;
        uint8_t*            ptrBuffRx;
    } rs485Interface_t;

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
    class Rs485 : public i_transport::ITransport
    {
    public:
        Rs485();

        bool transportInit(rs485Interface_t* ptrInterface);
        bool transportDeinit();
        bool transportReset() override;

        bool sendData(const uint8_t* ptrData, uint32_t len) override;
        bool getData(uint8_t* ptrData, uint32_t* lenInOut) override;

        void timerHandler();
        void rxneHandler();
        void tcHandler();
        void txeHandler();
        void errHandler();

    private:
        typedef enum
        {
            TXS_IDLE,
            TXS_RUN,
            TXS_SYNC
        } TX_STATE;

        typedef struct
        {
            TX_STATE    txState;
            uint16_t    txLen;
            uint16_t    txCount;

            bool        isRxReady;
            bool        isRxEn;
            uint16_t    rxLen;
            uint32_t    errCount;
        } logic_t;
    
        void restart();
    
        rs485Interface_t*   m_Interface;
        logic_t             m_logic;
    };
}
