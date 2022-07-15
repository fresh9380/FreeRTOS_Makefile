#ifndef __APP_H__
#define __APP_H__


#include "main.h"
#include "event_groups.h"
void AppTaskCreate(void);

extern TaskHandle_t AppTaskCreate_Handle;
extern EventGroupHandle_t Event_Handle;

#endif