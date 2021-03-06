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
// 4 //??????????????????????????????????????? stdint.h ??????
// 5 #if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__) (1)
// 6 #include <stdint.h>
// 7 extern uint32_t SystemCoreClock;
// 8 #endif
// 9
// 10 //??????
// 11 #define vAssertCalled(char,int) printf("Error:%s,%d\r\n",char,int)
// 12 #define configASSERT(x) if((x)==0) vAssertCalled(__FILE__,__LINE__) (2)
// 13
// 14 /************************************************************************
// 15 * FreeRTOS ????????????????????????
// 16 *********************************************************************/
// 17 /* ??? 1??? RTOS ?????????????????????????????? 0??? RTOS ???????????????????????????????????????
// 18 *
// 19 * ??????????????????????????????????????????????????????????????????????????????????????????
// 20 * ?????????????????????????????????????????? CPU ?????????????????????????????????
// 21 * ????????????????????????????????????????????????????????????
// 22 */
// 23 #define configUSE_PREEMPTION 1 (3)
// 24
// 25 //1 ?????????????????????(??????????????????)
// 26 #define configUSE_TIME_SLICING 1 (4)
// 27
// 28 /* ???????????? FreeRTOS ????????????????????????????????????????????????????????????
// 29 * ??????????????????????????????????????????????????????????????????????????????
// 30 *
// 31 * ???????????????
// 32 * 1.configUSE_PORT_OPTIMISED_TASK_SELECTION ??? 0 ??????????????????????????????????????????
// 33 * 2.?????????????????? FreeRTOS ???????????????
// 34 * 3.????????? C ???????????????????????????????????????
// 35 * 4.????????????????????????????????????????????????
// 36 * ???????????????
// 37 * 1.????????? configUSE_PORT_OPTIMISED_TASK_SELECTION ????????? 1???
// 38 * 2.?????????????????????????????????????????????????????????????????????????????????[CLZ]????????????
// 39 * 3.????????????????????????
// 40 * 4.???????????????????????????????????????????????? 32
// 41 *
// 42 ???????????????????????????????????????????????????????????? MCU ??????????????????????????????????????????????????? 0???
// 43 */
// 44 #define configUSE_PORT_OPTIMISED_TASK_SELECTION 1 (5)
// 45
// 46 /* ??? 1?????????????????? tickless ???????????? 0????????????????????????tick????????????????????? */
// 47 #define configUSE_TICKLESS_IDLE 0 (6)
// 48
// 49 /*
// 50 * ??????????????? CPU ?????????????????????????????? CPU ????????????????????????????????? Fclk
// 51 * Fclk ????????? CPU ??????????????????????????????????????? cpu ????????? XX MHz???
// 52 * ????????????????????????????????????????????? 1/Fclk ?????? cpu ???????????????
// 53 */
// 54 #define configCPU_CLOCK_HZ (SystemCoreClock) (7)
// 56 //RTOS ????????????????????????????????????????????????????????????????????? RTOS ????????????????????????
// 57 #define configTICK_RATE_HZ (( TickType_t )1000) (8)
// 58
// 59 //???????????????????????????
// 60 #define configMAX_PRIORITIES (32) (9)
// 61
// 62 //?????????????????????????????????
// 63 #define configMINIMAL_STACK_SIZE ((unsigned short)128) (10)
// 64
// 65 //???????????????????????????
// 66 #define configMAX_TASK_NAME_LE (16) (11)
// 67
// 68 //?????????????????????????????????????????? 1 ????????? 16 ????????????????????? 0 ????????? 32 ??????????????????
// 69 #define configUSE_16_BIT_TICKS 0 (12)
// 70
// 71 //?????????????????? CPU ?????????????????????????????????????????????
// 72 #define configIDLE_SHOULD_YIELD 1 (13)
// 73
// 74 //????????????
// 75 #define configUSE_QUEUE_SETS 1 (14)
// 76
// 77 //???????????????????????????????????????
// 78 #define configUSE_TASK_NOTIFICATIONS 1 (15)
// 79
// 80 //?????????????????????
// 81 #define configUSE_MUTEXES 1 (16)
// 82
// 83 //???????????????????????????
// 84 #define configUSE_RECURSIVE_MUTEXES 1 (17)
// 85
// 86 //??? 1 ????????????????????????
// 87 #define configUSE_COUNTING_SEMAPHORES 1 (18)
// 88
// 89 /* ??????????????????????????????????????????????????? */
// 90 #define configQUEUE_REGISTRY_SIZE 10 (19)
// 91
// 92 #define configUSE_APPLICATION_TASK_TAG 0
// 93
// 94
// 95 /*****************************************************************
// 96 FreeRTOS ?????????????????????????????????
// 97 *****************************************************************/
// 98 //????????????????????????
// 99 #define configSUPPORT_DYNAMIC_ALLOCATION 1 (20)
// 100 //??????????????????
// 101#define configSUPPORT_STATIC_ALLOCATION 0
// 102 //???????????????????????????
// 103 #define configTOTAL_HEAP_SIZE ((size_t)(36*1024)) (21)
// 104 /***************************************************************
// 105 FreeRTOS ????????????????????????????????????
// 106 **************************************************************/
// 107 /* ??? 1????????????????????????Idle Hook ?????????????????????????????? 0?????????????????????
// 108 *
// 109 * ?????????????????????????????????????????????????????????????????????
// 110 * FreeRTOS ???????????????????????????????????? void vApplicationIdleHook(void )???
// 111 * ??????????????????????????????????????????????????????
// 112 * ????????????????????? RTOS ??????????????????????????????????????????????????????????????????
// 113 * ??????????????????????????????????????? CPU ??????
// 114 * ?????????????????????????????? CPU ?????????????????????????????????
// 115 * ????????????????????????????????????????????? API ??????
// 116 */
// 117 #define configUSE_IDLE_HOOK 0 (22)
// 118
// 119 /* ??? 1???????????????????????????Tick Hook????????? 0????????????????????????
// 120 *
// 121 *
// 122 * ??????????????????????????????????????????????????????????????????
// 123 * FreeRTOS ???????????????????????????????????? void vApplicationTickHook(void )
// 124 * ???????????????????????????????????????
// 125 * ??????????????????????????????????????????????????????
// 126 * ??????????????????FromISR" ??? "FROM_ISR???????????? API ??????
// 127 */
// 128 #define configUSE_TICK_HOOK 0 (23)
// 129
// 130 //????????????????????????????????????
// 131 #define configUSE_MALLOC_FAILED_HOOK 0 (24)
// 132
// 133 /*
// 134 * ?????? 0 ?????????????????????????????????????????????????????????
// 135 * ??????????????????????????????????????????????????????????????????
// 136 * ??????????????? 1 ?????? 2??????????????????????????????????????? */
// 137 #define configCHECK_FOR_STACK_OVERFLOW 0 (25)
// 138
// 139
// 140 /********************************************************************
// 141 FreeRTOS ?????????????????????????????????????????????????????????
// 142 **********************************************************************/
// 143 //??????????????????????????????
// 144 #define configGENERATE_RUN_TIME_STATS 0 (26)
// 145 //???????????????????????????
// 146 #define configUSE_TRACE_FACILITY 0 (27)
// 147 /* ?????? configUSE_TRACE_FACILITY ????????? 1 ?????????????????? 3 ?????????
// 148 * prvWriteNameToBuffer()
// 149 * vTaskList(),
// 150 * vTaskGetRunTimeStats()
// 151 */
// 152 #define configUSE_STATS_FORMATTING_FUNCTIONS 1
// 153
// 154
// 155 /********************************************************************
// 156 FreeRTOS ??????????????????????????????
// 157 *********************************************************************/
// 158 //??????????????????????????????????????????????????? croutine.c
// 159 #define configUSE_CO_ROUTINES 0 (28)
// 160 //??????????????????????????????
// 161 #define configMAX_CO_ROUTINE_PRIORITIES ( 2 ) (29)
// 162
// 163
// 164 /***********************************************************************
// 165 FreeRTOS ???????????????????????????????????????
// 166 **********************************************************************/
// 167 //?????????????????????
// 168 #define configUSE_TIMERS 1 (30)
// 169 //????????????????????????
// 170 #define configTIMER_TASK_PRIORITY (configMAX_PRIORITIES-1) (31)
// 171 //???????????????????????????
// 172 #define configTIMER_QUEUE_LENGTH 10 (32)
// 173 //?????????????????????????????????
// 174 #define configTIMER_TASK_STACK_DEPTH (configMINIMAL_STACK_SIZE*2) (33)
// 175
// 176 /************************************************************
// 177 FreeRTOS ????????????????????????
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
// 191 FreeRTOS ??????????????????????????????
// 192 ******************************************************************/
// 193 #ifdef __NVIC_PRIO_BITS
// 194 #define configPRIO_BITS __NVIC_PRIO_BITS (38)
// 195 #else
// 196 #define configPRIO_BITS 4 (39)
// 197 #endif
// 198 //?????????????????????
// 199 #define configLIBRARY_LOWEST_INTERRUPT_PRIORITY 15 (40)
// 200
// 201 //???????????????????????????????????????
// 202 #define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY 5 (41)
// 203 #define configKERNEL_INTERRUPT_PRIORITY (42)
// 204 ( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
// 205
// 206 #define configMAX_SYSCALL_INTERRUPT_PRIORITY (43)
// 207 ( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
// 208 /****************************************************************
// 209 FreeRTOS ??????????????????????????????????????????
// 210 ****************************************************************/
// 211 #define xPortPendSVHandler PendSV_Handler
// 212 #define vPortSVCHandler SVC_Handler
// 213
// 214 /* ??????????????? Percepio Tracealyzer ?????????????????????????????????
// 215 configUSE_TRACE_FACILITY ????????? 0 */
// 216 #if ( configUSE_TRACE_FACILITY == 1 ) (44)
// 217 #include "trcRecorder.h"
// 218 #define INCLUDE_xTaskGetCurrentTaskHandle 0
// 219 // ??????????????????????????????????????? Trace ?????????????????????????????? 0 ???????????????
// 220 #endif
// 221
// 222
// 223 #endif /* FREERTOS_CONFIG_H */