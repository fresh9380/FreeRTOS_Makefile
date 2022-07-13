/*
    FreeRTOS V9.0.0 - Copyright (C) 2016 Real Time Engineers Ltd.
    All rights reserved

    VISIT http://www.FreeRTOS.org TO ENSURE YOU ARE USING THE LATEST VERSION.

    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation >>>> AND MODIFIED BY <<<< the FreeRTOS exception.

    ***************************************************************************
    >>!   NOTE: The modification to the GPL is included to allow you to     !<<
    >>!   distribute a combined work that includes FreeRTOS without being   !<<
    >>!   obliged to provide the source code for proprietary components     !<<
    >>!   outside of the FreeRTOS kernel.                                   !<<
    ***************************************************************************

    FreeRTOS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE.  Full license text is available on the following
    link: http://www.freertos.org/a00114.html

    ***************************************************************************
     *                                                                       *
     *    FreeRTOS provides completely free yet professionally developed,    *
     *    robust, strictly quality controlled, supported, and cross          *
     *    platform software that is more than just the market leader, it     *
     *    is the industry's de facto standard.                               *
     *                                                                       *
     *    Help yourself get started quickly while simultaneously helping     *
     *    to support the FreeRTOS project by purchasing a FreeRTOS           *
     *    tutorial book, reference manual, or both:                          *
     *    http://www.FreeRTOS.org/Documentation                              *
     *                                                                       *
    ***************************************************************************

    http://www.FreeRTOS.org/FAQHelp.html - Having a problem?  Start by reading
    the FAQ page "My application does not run, what could be wrong?".  Have you
    defined configASSERT()?

    http://www.FreeRTOS.org/support - In return for receiving this top quality
    embedded software for free we request you assist our global community by
    participating in the support forum.

    http://www.FreeRTOS.org/training - Investing in training allows your team to
    be as productive as possible as early as possible.  Now you can receive
    FreeRTOS training directly from Richard Barry, CEO of Real Time Engineers
    Ltd, and the world's leading authority on the world's leading RTOS.

    http://www.FreeRTOS.org/plus - A selection of FreeRTOS ecosystem products,
    including FreeRTOS+Trace - an indispensable productivity tool, a DOS
    compatible FAT file system, and our tiny thread aware UDP/IP stack.

    http://www.FreeRTOS.org/labs - Where new FreeRTOS products go to incubate.
    Come and try FreeRTOS+TCP, our new open source TCP/IP stack for FreeRTOS.

    http://www.OpenRTOS.com - Real Time Engineers ltd. license FreeRTOS to High
    Integrity Systems ltd. to sell under the OpenRTOS brand.  Low cost OpenRTOS
    licenses offer ticketed support, indemnification and commercial middleware.

    http://www.SafeRTOS.com - High Integrity Systems also provide a safety
    engineered and independently SIL3 certified version for use in safety and
    mission critical applications that require provable dependability.

    1 tab == 4 spaces!
*/


#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include "stm32f429xx.h"
/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *
 * See http://www.freertos.org/a00110.html.
 *----------------------------------------------------------*/

/* Ensure stdint is only used by the compiler, and not the assembler. */
#ifdef __ICCARM__
	#include <stdint.h>
	extern uint32_t SystemCoreClock;
#endif

#define configUSE_PREEMPTION			1
#define configUSE_IDLE_HOOK				0
#define configUSE_TICK_HOOK				0
#define configCPU_CLOCK_HZ				( SystemCoreClock )
#define configTICK_RATE_HZ				( ( TickType_t ) 1000 )
#define configMAX_PRIORITIES			( 5 )
#define configMINIMAL_STACK_SIZE		( ( unsigned short ) 130 )
#define configTOTAL_HEAP_SIZE			( ( size_t ) ( 75 * 1024 ) )
#define configMAX_TASK_NAME_LEN			( 10 )
#define configUSE_TRACE_FACILITY		1
#define configUSE_16_BIT_TICKS			0
#define configIDLE_SHOULD_YIELD			1
#define configUSE_MUTEXES				1
#define configQUEUE_REGISTRY_SIZE		8
#define configCHECK_FOR_STACK_OVERFLOW	0
#define configUSE_RECURSIVE_MUTEXES		1
#define configUSE_MALLOC_FAILED_HOOK	0
#define configUSE_APPLICATION_TASK_TAG	0
#define configUSE_COUNTING_SEMAPHORES	1
#define configGENERATE_RUN_TIME_STATS	0


#define configSUPPORT_STATIC_ALLOCATION 1


/* Co-routine definitions. */
#define configUSE_CO_ROUTINES 		0
#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )

/* Software timer definitions. */
#define configUSE_TIMERS				1
#define configTIMER_TASK_PRIORITY		( 2 )
#define configTIMER_QUEUE_LENGTH		10
#define configTIMER_TASK_STACK_DEPTH	( configMINIMAL_STACK_SIZE * 2 )

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */
#define INCLUDE_vTaskPrioritySet		1
#define INCLUDE_uxTaskPriorityGet		1
#define INCLUDE_vTaskDelete				1
#define INCLUDE_vTaskCleanUpResources	1
#define INCLUDE_vTaskSuspend			1
#define INCLUDE_vTaskDelayUntil			1
#define INCLUDE_vTaskDelay				1

/* Cortex-M specific definitions. */
#ifdef __NVIC_PRIO_BITS
	/* __BVIC_PRIO_BITS will be specified when CMSIS is being used. */
	#define configPRIO_BITS       		__NVIC_PRIO_BITS
#else
	#define configPRIO_BITS       		4        /* 15 priority levels */
#endif

/* The lowest interrupt priority that can be used in a call to a "set priority"
function. */
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY			0xf

/* The highest interrupt priority that can be used by any interrupt service
routine that makes calls to interrupt safe FreeRTOS API functions.  DO NOT CALL
INTERRUPT SAFE FREERTOS API FUNCTIONS FROM ANY INTERRUPT THAT HAS A HIGHER
PRIORITY THAN THIS! (higher priorities are lower numeric values. */
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY	5

/* Interrupt priorities used by the kernel port layer itself.  These are generic
to all Cortex-M ports, and do not rely on any particular library functions. */
#define configKERNEL_INTERRUPT_PRIORITY 		( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
/* !!!! configMAX_SYSCALL_INTERRUPT_PRIORITY must not be set to zero !!!!
See http://www.FreeRTOS.org/RTOS-Cortex-M3-M4.html. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
	
/* Normal assert() semantics without relying on the provision of an assert.h
header file. */
#define configASSERT( x ) if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }	
	
/* Definitions that map the FreeRTOS port interrupt handlers to their CMSIS
standard names. */
#define vPortSVCHandler SVC_Handler
#define xPortPendSVHandler PendSV_Handler
#define xPortSysTickHandler SysTick_Handler

#endif /* FREERTOS_CONFIG_H */




// #ifndef FREERTOS_CONFIG_H
// 2 #define FREERTOS_CONFIG_H
// 3
// 4 //针对不同的编译器调用不同的 stdint.h 文件
// 5 #if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__) (1)
// 6 #include <stdint.h>
// 7 extern uint32_t SystemCoreClock;
// 8 #endif
// 9
// 10 //断言
// 11 #define vAssertCalled(char,int) printf("Error:%s,%d\r\n",char,int)
// 12 #define configASSERT(x) if((x)==0) vAssertCalled(__FILE__,__LINE__) (2)
// 13
// 14 /************************************************************************
// 15 * FreeRTOS 基础配置配置选项
// 16 *********************************************************************/
// 17 /* 置 1： RTOS 使用抢占式调度器；置 0： RTOS 使用协作式调度器（时间片）
// 18 *
// 19 * 注：在多任务管理机制上，操作系统可以分为抢占式和协作式两种。
// 20 * 协作式操作系统是任务主动释放 CPU 后，切换到下一个任务。
// 21 * 任务切换的时机完全取决于正在运行的任务。
// 22 */
// 23 #define configUSE_PREEMPTION 1 (3)
// 24
// 25 //1 使能时间片调度(默认式使能的)
// 26 #define configUSE_TIME_SLICING 1 (4)
// 27
// 28 /* 某些运行 FreeRTOS 的硬件有两种方法选择下一个要执行的任务：
// 29 * 通用方法和特定于硬件的方法（以下简称“特殊方法”）。
// 30 *
// 31 * 通用方法：
// 32 * 1.configUSE_PORT_OPTIMISED_TASK_SELECTION 为 0 或者硬件不支持这种特殊方法。
// 33 * 2.可以用于所有 FreeRTOS 支持的硬件
// 34 * 3.完全用 C 实现，效率略低于特殊方法。
// 35 * 4.不强制要求限制最大可用优先级数目
// 36 * 特殊方法：
// 37 * 1.必须将 configUSE_PORT_OPTIMISED_TASK_SELECTION 设置为 1。
// 38 * 2.依赖一个或多个特定架构的汇编指令（一般是类似计算前导零[CLZ]指令）。
// 39 * 3.比通用方法更高效
// 40 * 4.一般强制限定最大可用优先级数目为 32
// 41 *
// 42 一般是硬件计算前导零指令，如果所使用的， MCU 没有这些硬件指令的话此宏应该设置为 0！
// 43 */
// 44 #define configUSE_PORT_OPTIMISED_TASK_SELECTION 1 (5)
// 45
// 46 /* 置 1：使能低功耗 tickless 模式；置 0：保持系统节拍（tick）中断一直运行 */
// 47 #define configUSE_TICKLESS_IDLE 0 (6)
// 48
// 49 /*
// 50 * 写入实际的 CPU 内核时钟频率，也就是 CPU 指令执行频率，通常称为 Fclk
// 51 * Fclk 为供给 CPU 内核的时钟信号，我们所说的 cpu 主频为 XX MHz，
// 52 * 就是指的这个时钟信号，相应的， 1/Fclk 即为 cpu 时钟周期；
// 53 */
// 54 #define configCPU_CLOCK_HZ (SystemCoreClock) (7)
// 56 //RTOS 系统节拍中断的频率。即一秒中断的次数，每次中断 RTOS 都会进行任务调度
// 57 #define configTICK_RATE_HZ (( TickType_t )1000) (8)
// 58
// 59 //可使用的最大优先级
// 60 #define configMAX_PRIORITIES (32) (9)
// 61
// 62 //空闲任务使用的堆栈大小
// 63 #define configMINIMAL_STACK_SIZE ((unsigned short)128) (10)
// 64
// 65 //任务名字字符串长度
// 66 #define configMAX_TASK_NAME_LE (16) (11)
// 67
// 68 //系统节拍计数器变量数据类型， 1 表示为 16 位无符号整形， 0 表示为 32 位无符号整形
// 69 #define configUSE_16_BIT_TICKS 0 (12)
// 70
// 71 //空闲任务放弃 CPU 使用权给其他同优先级的用户任务
// 72 #define configIDLE_SHOULD_YIELD 1 (13)
// 73
// 74 //启用队列
// 75 #define configUSE_QUEUE_SETS 1 (14)
// 76
// 77 //开启任务通知功能，默认开启
// 78 #define configUSE_TASK_NOTIFICATIONS 1 (15)
// 79
// 80 //使用互斥信号量
// 81 #define configUSE_MUTEXES 1 (16)
// 82
// 83 //使用递归互斥信号量
// 84 #define configUSE_RECURSIVE_MUTEXES 1 (17)
// 85
// 86 //为 1 时使用计数信号量
// 87 #define configUSE_COUNTING_SEMAPHORES 1 (18)
// 88
// 89 /* 设置可以注册的信号量和消息队列个数 */
// 90 #define configQUEUE_REGISTRY_SIZE 10 (19)
// 91
// 92 #define configUSE_APPLICATION_TASK_TAG 0
// 93
// 94
// 95 /*****************************************************************
// 96 FreeRTOS 与内存申请有关配置选项
// 97 *****************************************************************/
// 98 //支持动态内存申请
// 99 #define configSUPPORT_DYNAMIC_ALLOCATION 1 (20)
// 100 //支持静态内存
// 101#define configSUPPORT_STATIC_ALLOCATION 0
// 102 //系统所有总的堆大小
// 103 #define configTOTAL_HEAP_SIZE ((size_t)(36*1024)) (21)
// 104 /***************************************************************
// 105 FreeRTOS 与钩子函数有关的配置选项
// 106 **************************************************************/
// 107 /* 置 1：使用空闲钩子（Idle Hook 类似于回调函数）；置 0：忽略空闲钩子
// 108 *
// 109 * 空闲任务钩子是一个函数，这个函数由用户来实现，
// 110 * FreeRTOS 规定了函数的名字和参数： void vApplicationIdleHook(void )，
// 111 * 这个函数在每个空闲任务周期都会被调用
// 112 * 对于已经删除的 RTOS 任务，空闲任务可以释放分配给它们的堆栈内存。
// 113 * 因此必须保证空闲任务可以被 CPU 执行
// 114 * 使用空闲钩子函数设置 CPU 进入省电模式是很常见的
// 115 * 不可以调用会引起空闲任务阻塞的 API 函数
// 116 */
// 117 #define configUSE_IDLE_HOOK 0 (22)
// 118
// 119 /* 置 1：使用时间片钩子（Tick Hook）；置 0：忽略时间片钩子
// 120 *
// 121 *
// 122 * 时间片钩子是一个函数，这个函数由用户来实现，
// 123 * FreeRTOS 规定了函数的名字和参数： void vApplicationTickHook(void )
// 124 * 时间片中断可以周期性的调用
// 125 * 函数必须非常短小，不能大量使用堆栈，
// 126 * 不能调用以”FromISR" 或 "FROM_ISR”结尾的 API 函数
// 127 */
// 128 #define configUSE_TICK_HOOK 0 (23)
// 129
// 130 //使用内存申请失败钩子函数
// 131 #define configUSE_MALLOC_FAILED_HOOK 0 (24)
// 132
// 133 /*
// 134 * 大于 0 时启用堆栈溢出检测功能，如果使用此功能
// 135 * 用户必须提供一个栈溢出钩子函数，如果使用的话
// 136 * 此值可以为 1 或者 2，因为有两种栈溢出检测方法 */
// 137 #define configCHECK_FOR_STACK_OVERFLOW 0 (25)
// 138
// 139
// 140 /********************************************************************
// 141 FreeRTOS 与运行时间和任务状态收集有关的配置选项
// 142 **********************************************************************/
// 143 //启用运行时间统计功能
// 144 #define configGENERATE_RUN_TIME_STATS 0 (26)
// 145 //启用可视化跟踪调试
// 146 #define configUSE_TRACE_FACILITY 0 (27)
// 147 /* 与宏 configUSE_TRACE_FACILITY 同时为 1 时会编译下面 3 个函数
// 148 * prvWriteNameToBuffer()
// 149 * vTaskList(),
// 150 * vTaskGetRunTimeStats()
// 151 */
// 152 #define configUSE_STATS_FORMATTING_FUNCTIONS 1
// 153
// 154
// 155 /********************************************************************
// 156 FreeRTOS 与协程有关的配置选项
// 157 *********************************************************************/
// 158 //启用协程，启用协程以后必须添加文件 croutine.c
// 159 #define configUSE_CO_ROUTINES 0 (28)
// 160 //协程的有效优先级数目
// 161 #define configMAX_CO_ROUTINE_PRIORITIES ( 2 ) (29)
// 162
// 163
// 164 /***********************************************************************
// 165 FreeRTOS 与软件定时器有关的配置选项
// 166 **********************************************************************/
// 167 //启用软件定时器
// 168 #define configUSE_TIMERS 1 (30)
// 169 //软件定时器优先级
// 170 #define configTIMER_TASK_PRIORITY (configMAX_PRIORITIES-1) (31)
// 171 //软件定时器队列长度
// 172 #define configTIMER_QUEUE_LENGTH 10 (32)
// 173 //软件定时器任务堆栈大小
// 174 #define configTIMER_TASK_STACK_DEPTH (configMINIMAL_STACK_SIZE*2) (33)
// 175
// 176 /************************************************************
// 177 FreeRTOS 可选函数配置选项
// 178 ************************************************************/
// 179 #define INCLUDE_xTaskGetSchedulerState 1 (34)
// 180 #define INCLUDE_vTaskPrioritySet 1 (35)
// 181 #define INCLUDE_uxTaskPriorityGet 1 (36)
// 182 #define INCLUDE_vTaskDelete 1 (37)
// 183 #define INCLUDE_vTaskCleanUpResources 1
// 184 #define INCLUDE_vTaskSuspend 1
// 185 #define INCLUDE_vTaskDelayUntil 1
// 186 #define INCLUDE_vTaskDelay 1
// 187 #define INCLUDE_eTaskGetState 1
// 188 #define INCLUDE_xTimerPendFunctionCall 1
// 189
// 190 /******************************************************************
// 191 FreeRTOS 与中断有关的配置选项
// 192 ******************************************************************/
// 193 #ifdef __NVIC_PRIO_BITS
// 194 #define configPRIO_BITS __NVIC_PRIO_BITS (38)
// 195 #else
// 196 #define configPRIO_BITS 4 (39)
// 197 #endif
// 198 //中断最低优先级
// 199 #define configLIBRARY_LOWEST_INTERRUPT_PRIORITY 15 (40)
// 200
// 201 //系统可管理的最高中断优先级
// 202 #define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY 5 (41)
// 203 #define configKERNEL_INTERRUPT_PRIORITY (42)
// 204 ( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
// 205
// 206 #define configMAX_SYSCALL_INTERRUPT_PRIORITY (43)
// 207 ( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
// 208 /****************************************************************
// 209 FreeRTOS 与中断服务函数有关的配置选项
// 210 ****************************************************************/
// 211 #define xPortPendSVHandler PendSV_Handler
// 212 #define vPortSVCHandler SVC_Handler
// 213
// 214 /* 以下为使用 Percepio Tracealyzer 需要的东西，不需要时将
// 215 configUSE_TRACE_FACILITY 定义为 0 */
// 216 #if ( configUSE_TRACE_FACILITY == 1 ) (44)
// 217 #include "trcRecorder.h"
// 218 #define INCLUDE_xTaskGetCurrentTaskHandle 0
// 219 // 启用一个可选函数（该函数被 Trace 源码使用，默认该值为 0 表示不用）
// 220 #endif
// 221
// 222
// 223 #endif /* FREERTOS_CONFIG_H */