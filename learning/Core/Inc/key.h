#ifndef __KEY_H__
#define __KEY_H__

#include "main.h"
#include "app.h"

#define EVENT1 (0x01 << 0)//设置事件掩码的位 0
#define EVENT2 (0x01 << 1)//设置事件掩码的位 1
#define EVENT3 (0x01 << 2)//设置事件掩码的位 1

GPIO_PinState KeyScan(void);
void KeyScan_Task(void);

#endif