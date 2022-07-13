#include "FreeRTOS.h"
#include "task.h"
#include "led.h"
/**************************** 任务句柄 ********************************/
 /*
 * 任务句柄是一个指针，用于指向一个任务，当任务创建好之后，它就具有了一个任务句柄
 * 以后我们要想操作这个任务都需要通过这个任务句柄，如果是自身的任务操作自己，那么
 * 这个句柄可以为 NULL。
 */

 /* LED 任务句柄 */
 static TaskHandle_t LED_Task_Handle;


 /* LED 任务堆栈 */
 static StackType_t LED_Task_Stack[128];


 /* AppTaskCreate 任务控制块 */
 static StaticTask_t LED_Task_TCB;


void AppTaskCreate(void)
{
    taskENTER_CRITICAL();

    LED_Task_Handle = xTaskCreateStatic((TaskFunction_t)LED_Func, //任务函数(1)
                            (const char* )"LED_Func",//任务名称(2)
                            (uint32_t )128, //任务堆栈大小 (3)
                            (void* )NULL, //传递给任务函数的参数(4)
                            (UBaseType_t )4, //任务优先级 (5)
                            (StackType_t* )LED_Task_Stack, //任务堆栈(6)
                            (StaticTask_t* )&LED_Task_TCB); //任务控制块(7)
                            
    if (NULL != LED_Task_Handle) /* 创建成功 */
    {
        LOGD("LED_Task creats success!");
    }
    else
    {
        LOGD("LED_Task creats failed!");
    }
    
    vTaskDelete(AppTaskCreate_Handle); //删除 AppTaskCreate 任务

    taskEXIT_CRITICAL(); //退出临界区

}




