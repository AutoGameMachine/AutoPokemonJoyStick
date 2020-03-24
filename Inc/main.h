/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

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

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define key1_Pin GPIO_PIN_3
#define key1_GPIO_Port GPIOE
#define key0_Pin GPIO_PIN_4
#define key0_GPIO_Port GPIOE
#define led1_Pin GPIO_PIN_5
#define led1_GPIO_Port GPIOE
#define pc1_Pin GPIO_PIN_0
#define pc1_GPIO_Port GPIOA
#define pc2_Pin GPIO_PIN_1
#define pc2_GPIO_Port GPIOA
#define pc3_Pin GPIO_PIN_4
#define pc3_GPIO_Port GPIOA
#define pc4_Pin GPIO_PIN_5
#define pc4_GPIO_Port GPIOA
#define pc5_Pin GPIO_PIN_6
#define pc5_GPIO_Port GPIOA
#define pc6_Pin GPIO_PIN_7
#define pc6_GPIO_Port GPIOA
#define pc12_Pin GPIO_PIN_4
#define pc12_GPIO_Port GPIOC
#define pc11_Pin GPIO_PIN_5
#define pc11_GPIO_Port GPIOC
#define pc10_Pin GPIO_PIN_0
#define pc10_GPIO_Port GPIOB
#define pc9_Pin GPIO_PIN_1
#define pc9_GPIO_Port GPIOB
#define pc8_Pin GPIO_PIN_2
#define pc8_GPIO_Port GPIOB
#define pc7_Pin GPIO_PIN_11
#define pc7_GPIO_Port GPIOF
#define led0_Pin GPIO_PIN_5
#define led0_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
