/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/

#include "main.h"

 /* 创建任务句柄 */
TaskHandle_t AppTaskCreate_Handle;

/* AppTaskCreate 任务任务堆栈 */
 static StackType_t AppTaskCreate_Stack[128];
 /* 空闲任务任务堆栈 */
 static StackType_t Idle_Task_Stack[configMINIMAL_STACK_SIZE];
 /* 定时器任务堆栈 */
static StackType_t Timer_Task_Stack[configTIMER_TASK_STACK_DEPTH];


/* AppTaskCreate 任务控制块 */
static StaticTask_t AppTaskCreate_TCB;
/* 空闲任务控制块 */
static StaticTask_t Idle_Task_TCB;
/* 定时器任务控制块 */
static StaticTask_t Timer_Task_TCB;

int main(void)
{
  
  LOGD("beginning rtos");
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */

  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  // /* Initialize all configured peripherals */
  MX_GPIO_Init();
  // MX_TIM2_Init();
  // MX_USART1_Init();
  
  AppTaskCreate_Handle = xTaskCreateStatic((TaskFunction_t)AppTaskCreate, //任务函数(1)
                            (const char* )"AppTaskCreate",//任务名称(2)
                            (uint32_t )128, //任务堆栈大小 (3)
                            (void* )NULL, //传递给任务函数的参数(4)
                            (UBaseType_t )3, //任务优先级 (5)
                            (StackType_t* )AppTaskCreate_Stack, //任务堆栈(6)
                            (StaticTask_t* )&AppTaskCreate_TCB); //任务控制块(7)

  if( AppTaskCreate_Handle == NULL) 
  {
    LOGE("task creat failed");
  }
  else 
  {
    vTaskStartScheduler();
  }

  while(1);
}

void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer,
StackType_t **ppxIdleTaskStackBuffer,
uint32_t *pulIdleTaskStackSize)
{
  *ppxIdleTaskTCBBuffer=&Idle_Task_TCB;/* 任务控制块内存 */
  *ppxIdleTaskStackBuffer=Idle_Task_Stack;/* 任务堆栈内存 */
  *pulIdleTaskStackSize=configMINIMAL_STACK_SIZE;/* 任务堆栈大小 */
}

 /**
 *********************************************************************
 * @brief 获取定时器任务的任务堆栈和任务控制块内存
 * ppxTimerTaskTCBBuffer : 任务控制块内存
 * ppxTimerTaskStackBuffer : 任务堆栈内存
 * pulTimerTaskStackSize : 任务堆栈大小
 * @author fire
 * @version V1.0
 * @date 2018-xx-xx
 **********************************************************************
 */
 void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer,
 StackType_t **ppxTimerTaskStackBuffer,
 uint32_t *pulTimerTaskStackSize)
 {
    *ppxTimerTaskTCBBuffer=&Timer_Task_TCB;/* 任务控制块内存 */
    *ppxTimerTaskStackBuffer=Timer_Task_Stack;/* 任务堆栈内存 */
    *pulTimerTaskStackSize=configTIMER_TASK_STACK_DEPTH;/* 任务堆栈大小 */
 }

 /**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}