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
#include "oled.h"
#include "usb_device.h"
#include "usbd_cdc_if.h"

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
/* Definitions for Oled */
osThreadId_t OledHandle;
const osThreadAttr_t Oled_attributes = {
  .name = "Oled",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for Max */
osThreadId_t MaxHandle;
const osThreadAttr_t Max_attributes = {
  .name = "Max",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartOled(void *argument);
void StartMax(void *argument);

extern void MX_USB_DEVICE_Init(void);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

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
  /* creation of Oled */
  OledHandle = osThreadNew(StartOled, NULL, &Oled_attributes);

  /* creation of Max */
  MaxHandle = osThreadNew(StartMax, NULL, &Max_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartOled */
/**
  * @brief  Function implementing the Oled thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartOled */
void StartOled(void *argument)
{
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN StartOled */
  /* Infinite loop */
  uint8_t send_data[]="usb_otg_fs!abcdefghijklmnopqrstuvwxyz\r\n";
  for(;;)
  { 
    OLED_ShowString(0,0 ,"hello" ,8 );
    CDC_Transmit_FS(send_data,sizeof(send_data));
    osDelay(500);
    OLED_ShowString(10,10 ,"world" ,8 );
    osDelay(200);
  }
  /* USER CODE END StartOled */
}

/* USER CODE BEGIN Header_StartMax */
/**
* @brief Function implementing the Max thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartMax */
void StartMax(void *argument)
{
  /* USER CODE BEGIN StartMax */
  /* Infinite loop */
  for(;;)
  { 
    osDelay(200);
    OLED_ShowString(0,0 ,"world" ,8 );
    osDelay(500);
    OLED_ShowString(10,10 ,"hello" ,8 );
  }
  /* USER CODE END StartMax */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

