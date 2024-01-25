/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f1xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "74HC595.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
uint16_t buffer;
int i=0 , ch;
const uint8_t images[16][8]=  {
{0B11101111,0B11001111,0B11101111,0B11101111,0B11101111,0B11101111,0B11101111,0B11000111},
{0B11000111,0B10111011,0B11111011,0B11111011,0B11110111,0B11101111,0B11011111,0B10000011},
{0B11000111,0B10111011,0B11111011,0B11100111,0B11111011,0B11111011,0B10111011,0B11000111},
{0B11100111,0B11000011,0B10011001,0B10011001,0B10000001,0B10011001,0B10011001,0B11111111},
{0B11111011,0B11110011,0B11101011,0B11011011,0B10111011,0B10000011,0B11111011,0B11111011},
{0B10000011,0B10111111,0B10111111,0B10000111,0B11111011,0B11111011,0B10111011,0B11000111},
{0B11000111,0B10111011,0B10111111,0B10000111,0B10111011,0B10111011,0B10111011,0B11000111},
{0B00000011,0B10011001,0B10011001,0B10000011,0B10011001,0B10011001,0B00000011,0B11111111},
{0B10000011,0B11111011,0B11111011,0B11110111,0B11101111,0B11011111,0B11011111,0B11011111},
{0B11000111,0B10111011,0B10111011,0B11000111,0B10111011,0B10111011,0B10111011,0B11000111},
{0B11000111,0B10111011,0B10111011,0B10111011,0B11000011,0B11111011,0B10111011,0B11000111},
{0B11000011,0B10011001,0B00111111,0B00111111,0B00111111,0B10011001,0B11000011,0B11111111},
{0B11111111,0B10011001,0B11000011,0B00000000,0B11000011,0B10011001,0B11111111,0B11111111},
{0B11000111,0B10111011,0B10111011,0B10111011,0B10111011,0B10111011,0B10111011,0B11000111},
{0B10010011,0B10010011,0B00000001,0B10010011,0B00000001,0B10010011,0B10010011,0B11111111},
{0B00000111,0B10010011,0B10011001,0B10011001,0B10011001,0B10010011,0B00000111,0B11111111} };
const uint8_t rows[8]= {
0B00000001,0B00000010,0B00000100,0B00001000,0B00010000,0B00100000,0B01000000,0B10000000,
};


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim2;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M3 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f1xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles TIM2 global interrupt.
  */
void TIM2_IRQHandler(void)
{
  /* USER CODE BEGIN TIM2_IRQn 0 */
i++;
if(i==8)  i=0;
HC595_SendByte((rows[i]),(images[ch][i] ));
  /* USER CODE END TIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&htim2);
  /* USER CODE BEGIN TIM2_IRQn 1 */

  /* USER CODE END TIM2_IRQn 1 */
}

/**
  * @brief This function handles EXTI line[15:10] interrupts.
  */
void EXTI15_10_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI15_10_IRQn 0 */

  /* USER CODE END EXTI15_10_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_12);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_14);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_15);
  /* USER CODE BEGIN EXTI15_10_IRQn 1 */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
  if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)==1)    ch=1;
  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13)==1)    ch=2;
  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14)==1)    ch=3;
  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15)==1)    ch=4;
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
  if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)==1)    ch=5;
  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13)==1)    ch=6;
  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14)==1)    ch=7;
  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15)==1)    ch=8;
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
  if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)==1)    ch=9;
  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13)==1)    ch=10;
  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14)==1)    ch=11;
  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15)==1)    ch=12;
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
  if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)==1)    ch=13;
  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13)==1)    ch=14;
  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14)==1)    ch=15;
  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15)==1)    ch=16;
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);













  /* USER CODE END EXTI15_10_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
