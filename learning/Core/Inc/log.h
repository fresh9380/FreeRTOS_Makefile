#ifndef __LOG_H__
#define __LOG_H__

#define LOGD(format,...)  SEGGER_RTT_printf(0,"[debug]"format"\r\n",##__VA_ARGS__);
#define LOGI(format,...)  SEGGER_RTT_printf(0,"[info]"format"\r\n",##__VA_ARGS__);
#define LOGE(format,...)  SEGGER_RTT_printf(0,"[error]"format"\r\n",##__VA_ARGS__);


#endif