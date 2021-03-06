#include "FreeRTOS.h"
#include "task.h"
#include "led.h"
#include "key.h"
/**************************** 任务句柄 ********************************/
 /*
 * 任务句柄是一个指针，用于指向一个任务，当任务创建好之后，它就具有了一个任务句柄
 * 以后我们要想操作这个任务都需要通过这个任务句柄，如果是自身的任务操作自己，那么
 * 这个句柄可以为 NULL。
 */

 /*事件组句柄 */
EventGroupHandle_t Event_Handle =NULL;


 /* LED 任务句柄 */
 static TaskHandle_t LED_Task_Handle;
 /* KEY_Task 任务句柄 */
 static TaskHandle_t KEY_Task_Handle = NULL;

 /* LED 任务堆栈 */
 static StackType_t LED_Task_Stack[128];


 /* AppTaskCreate 任务控制块 */
 static StaticTask_t LED_Task_TCB;


void AppTaskCreate(void)
{
    BaseType_t xReturn = pdPASS;

    taskENTER_CRITICAL();

    /* 创建 Event_Handle */
    Event_Handle = xEventGroupCreate();
    if (NULL != Event_Handle)
    LOGD("Event_Handle creats success!");

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

    /* 创建 KEY_Task 任务 */
    xReturn = xTaskCreate((TaskFunction_t )KeyScan_Task, /* 任务入口函数 */
                            (const char* )"KeyScan_Task",/* 任务名字 */
                            (uint16_t )512, /* 任务栈大小 */
                            (void* )NULL,/* 任务入口函数参数 */
                            (UBaseType_t )3, /* 任务的优先级 */
                            (TaskHandle_t* )&KEY_Task_Handle);/* 任务控制块指针 */

    if (pdPASS == xReturn)
    {
        LOGD("KEY_Task creats success!");
    }
    
    
    vTaskDelete(AppTaskCreate_Handle); //删除 AppTaskCreate 任务

    taskEXIT_CRITICAL(); //退出临界区

}




