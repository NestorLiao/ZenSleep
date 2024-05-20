/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "OLED.h"
#include "Max30102.h"
#include "usart.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for MaxSample */
osThreadId_t MaxSampleHandle;
const osThreadAttr_t MaxSample_attributes = {
  .name = "MaxSample",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for OledUpdate */
osThreadId_t OledUpdateHandle;
const osThreadAttr_t OledUpdate_attributes = {
  .name = "OledUpdate",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for UsartUpdate */
osThreadId_t UsartUpdateHandle;
const osThreadAttr_t UsartUpdate_attributes = {
  .name = "UsartUpdate",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for Algorithm */
osThreadId_t AlgorithmHandle;
const osThreadAttr_t Algorithm_attributes = {
  .name = "Algorithm",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartMaxSample(void *argument);
void StartOledUpdate(void *argument);
void StartUsartUpdate(void *argument);
void StartAlgorithm(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
    // Max30102_Safety();
  // OLED_ShowString(4,1,"hello");
    // OLED_ShowString(4,3,"begining");
    // HAL_UART_Transmit(&huart1, "begining", 1, 0xFFFF);

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of MaxSample */
  MaxSampleHandle = osThreadNew(StartMaxSample, NULL, &MaxSample_attributes);

  /* creation of OledUpdate */
  OledUpdateHandle = osThreadNew(StartOledUpdate, NULL, &OledUpdate_attributes);

  /* creation of UsartUpdate */
  UsartUpdateHandle = osThreadNew(StartUsartUpdate, NULL, &UsartUpdate_attributes);

  /* creation of Algorithm */
  AlgorithmHandle = osThreadNew(StartAlgorithm, NULL, &Algorithm_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartMaxSample */
/**
  * @brief  Function implementing the MaxSample thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartMaxSample */
void StartMaxSample(void *argument)
{
  /* USER CODE BEGIN StartMaxSample */
  /* Infinite loop */
  for(;;)
  {
	// Read();
    osDelay(1);
  }
  /* USER CODE END StartMaxSample */
}

/* USER CODE BEGIN Header_StartOledUpdate */
/**
* @brief Function implementing the OledUpdate thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartOledUpdate */
void StartOledUpdate(void *argument)
{
  /* USER CODE BEGIN StartOledUpdate */
  /* Infinite loop */
  for(;;)
  {
    
    OLED_ShowString(4,1,"hello");
    osDelay(100);
  }
  /* USER CODE END StartOledUpdate */
}

/* USER CODE BEGIN Header_StartUsartUpdate */
/**
* @brief Function implementing the UsartUpdate thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartUsartUpdate */
void StartUsartUpdate(void *argument)
{
  /* USER CODE BEGIN StartUsartUpdate */
  


  char myString[5];   // 定义一个包含字符的字符数组，这里假设只有一个字符
  myString[0] = 'A';  // 将字符存储到字符数组中
  myString[1] = 'B';    // 添加字符串终止符
  myString[2] = 'C';    // 添加字符串终止符
  myString[3] = '\r';    // 添加字符串终止符
  myString[4] = '\n';    // 添加字符串终止符

  
  /* Infinite loop */
  for(;;)
  {
    HAL_UART_Transmit(&huart1, (uint8_t *)myString, 5, 100);  // 传递字符数组给函数  
    osDelay(100);
  }
  /* USER CODE END StartUsartUpdate */
}

/* USER CODE BEGIN Header_StartAlgorithm */
/**
* @brief Function implementing the Algorithm thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartAlgorithm */
void StartAlgorithm(void *argument)
{
  /* USER CODE BEGIN StartAlgorithm */
  /* Infinite loop */
  for(;;)
  {
    // OLED_Clear();
    OLED_ShowString(4,7,"hello");
    osDelay(10);
  }
  /* USER CODE END StartAlgorithm */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

