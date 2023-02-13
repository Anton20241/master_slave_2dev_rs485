/**
 *  @file       pin_addr.hpp
 *  @brief      Определение адреса устройства по сигналам на входных пинах
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#pragma once

/* Includes ------------------------------------------------------------------*/
#include "main.h"

namespace pin_addr
{
    typedef struct
    {
        uint8_t         numPins;
        GPIO_TypeDef**  ptrPorts;
        uint16_t*       ptrPins;
        uint8_t         shiftAddr;
    } pinAddrConfig_t;

    class PinAddr
    {
        public:
            PinAddr(const pinAddrConfig_t* ptrConfig) :
                m_ptrConfig(ptrConfig)
            {}

            uint8_t getAddr()
            {
                uint8_t addr = 0;

                HAL_Delay(200);

                for (uint8_t i = 0; i < m_ptrConfig->numPins; i++) {
                    if (HAL_GPIO_ReadPin(   m_ptrConfig->ptrPorts[i],
                                            m_ptrConfig->ptrPins[i]) == \
                        GPIO_PIN_RESET) {
                        addr |= (1 << i);
                    }
                }
                return (addr + m_ptrConfig->shiftAddr);
            }
        private:
            const pinAddrConfig_t*      m_ptrConfig;
    };
}
