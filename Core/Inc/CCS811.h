#ifndef __CCS811_H
#define __CCS811_H
#include "stm32l4xx_hal.h"


#define TVOC_Adress 0x5A << 1 

#define STATUS                    0x00
#define MEAS_MODE                 0x01
#define ALG_RESULT_DATA           0x02 
#define RAW_DATA                  0x03 
#define ENV_DATA                  0x05 
#define NTC                       0x06 
#define THRESHOLDS                0x10 
#define BASELINE                  0x11 
#define HW_ID                     0x20 
#define HW_Version                0x21 
#define FW_Boot_Version           0x23 
#define FW_App_Version            0x24 
#define ERROR_ID                  0xE0 
#define APP_START_REG1            0xF4 
#define SW_RESET                  0xFF 

void CCS811_ini (void);
//uint16_t eco2_get_data(void);

#endif   
