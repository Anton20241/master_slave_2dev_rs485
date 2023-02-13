/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
#define register
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

#include "stm32f1xx_ll_tim.h"
#include "stm32f1xx_ll_usart.h"
#include "stm32f1xx_ll_rcc.h"
#include "stm32f1xx_ll_bus.h"
#include "stm32f1xx_ll_system.h"
#include "stm32f1xx_ll_exti.h"
#include "stm32f1xx_ll_cortex.h"
#include "stm32f1xx_ll_utils.h"
#include "stm32f1xx_ll_pwr.h"
#include "stm32f1xx_ll_dma.h"
#include "stm32f1xx_ll_gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void irq_tim4_handler(void);
void irq_uart1_handler(void);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define POZ_Pin GPIO_PIN_0
#define POZ_GPIO_Port GPIOA
#define ANGLE_POT_Pin GPIO_PIN_1
#define ANGLE_POT_GPIO_Port GPIOA
#define CURR_MOT_Pin GPIO_PIN_2
#define CURR_MOT_GPIO_Port GPIOA
#define PMODE_MOT_Pin GPIO_PIN_3
#define PMODE_MOT_GPIO_Port GPIOA
#define FAULT_MOT_Pin GPIO_PIN_4
#define FAULT_MOT_GPIO_Port GPIOA
#define SLEEP_MOT_Pin GPIO_PIN_5
#define SLEEP_MOT_GPIO_Port GPIOA
#define PWM_A_MOT_Pin GPIO_PIN_6
#define PWM_A_MOT_GPIO_Port GPIOA
#define PWM_B_MOT_Pin GPIO_PIN_7
#define PWM_B_MOT_GPIO_Port GPIOA
#define SCL_POT_Pin GPIO_PIN_10
#define SCL_POT_GPIO_Port GPIOB
#define SDA_POT_Pin GPIO_PIN_11
#define SDA_POT_GPIO_Port GPIOB
#define ADDR_1_Pin GPIO_PIN_12
#define ADDR_1_GPIO_Port GPIOB
#define SCK_TEN_Pin GPIO_PIN_13
#define SCK_TEN_GPIO_Port GPIOB
#define MISO_TEN_Pin GPIO_PIN_14
#define MISO_TEN_GPIO_Port GPIOB
#define ADDR_0_Pin GPIO_PIN_15
#define ADDR_0_GPIO_Port GPIOB
#define USART_DIR_Pin GPIO_PIN_8
#define USART_DIR_GPIO_Port GPIOA
#define ADDR_2_Pin GPIO_PIN_5
#define ADDR_2_GPIO_Port GPIOB
#define SCL_PRSH_Pin GPIO_PIN_6
#define SCL_PRSH_GPIO_Port GPIOB
#define SDA_PRSH_Pin GPIO_PIN_7
#define SDA_PRSH_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
