#include "led.h"
#include "FreeRTOS.h"
#include "main.h"
#include "key.h"

#define LED_ON   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
#define LED_OFF  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  __HAL_RCC_GPIOA_CLK_ENABLE();
  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);

  /*Configure GPIO pin : PD12 */
  GPIO_InitStruct.Pin = GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

   /*Configure GPIO pin : PD12 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

void LED_Func(void)
{
  EventBits_t r_event; /* 定义一个事件接收变量 */

  while(1)
  {
    r_event = xEventGroupWaitBits(Event_Handle, /* 事件对象句柄 */
                  EVENT1|EVENT2|EVENT3,/* 接收任务感兴趣的事件 */
                  pdTRUE, /* 退出时清除事件位 */
                  pdTRUE, /* 满足感兴趣的所有事件 */
                  3000);/* 指定超时事件,一直等 */
    
    if ((r_event & (EVENT1|EVENT2|EVENT3)) == (EVENT1))
    {
      LED_ON;
      vTaskDelay(1000); /* 延时 500 个 tick */
      LOGI("Event1_task running,LED1_ON");

      LED_OFF;
      vTaskDelay(1000); /* 延时 500 个 tick */
      LOGI("Event1_task running,LED1_OFF");
    }
    else if( (r_event & (EVENT1|EVENT2|EVENT3)) == (EVENT2))
    {
      LED_ON;
      vTaskDelay(100); /* 延时 500 个 tick */
      LOGI("Event2_task running,LED1_ON");

      LED_OFF;
      vTaskDelay(100); /* 延时 500 个 tick */
      LOGI("Event2_task running,LED1_OFF");
    }
    else if( (r_event & (EVENT1|EVENT2|EVENT3)) == (EVENT3))
    {
      LED_OFF;
      LOGI("Event3_task running,LED1_OFF");
    }
  }
}
