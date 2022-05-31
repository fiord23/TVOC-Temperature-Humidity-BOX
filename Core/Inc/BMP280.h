#include "stdint.h"
#ifndef _BMP280_H_
#define _BMP280_H_

#define BMP280_ADDRESS          0x77<<1
/*REGISTERS*/
#define BMP280_TEMP_XLSB        0xFC
#define BMP280_TEMP_LSB         0xFB
#define BMP280_TEMP_MSB         0xFA
#define BMP280_PRESS_XLSB       0xF9
#define BMP280_PRESS_LSB        0xF8
#define BMP280_PRESS_MSB        0xF7
#define BMP280_CONFIG           0xF5
#define BMP280_CTRL_MEAS        0xF4
#define BMP280_STATUS           0xF3
#define BMP280_RESET            0xE0
#define BMP280_ID               0xD0

#define BMP280_CALIB_25        0xA1
#define BMP280_CALIB_24        0xA0
#define BMP280_CALIB_23        0x9F
#define BMP280_CALIB_22        0x9E
#define BMP280_CALIB_21        0x9D
#define BMP280_CALIB_20        0x9C
#define BMP280_CALIB_19        0x9B
#define BMP280_CALIB_18        0x9A
#define BMP280_CALIB_17        0x99
#define BMP280_CALIB_16        0x98
#define BMP280_CALIB_15        0x97
#define BMP280_CALIB_14        0x96
#define BMP280_CALIB_13        0x95
#define BMP280_CALIB_12        0x94
#define BMP280_CALIB_11        0x93
#define BMP280_CALIB_10        0x92
#define BMP280_CALIB_09        0x91
#define BMP280_CALIB_08        0x90
#define BMP280_CALIB_07        0x8F
#define BMP280_CALIB_06        0x8E
#define BMP280_CALIB_05        0x8D
#define BMP280_CALIB_04        0x8C
#define BMP280_CALIB_03        0x8B
#define BMP280_CALIB_02        0x8A
#define BMP280_CALIB_01        0x89
#define BMP280_CALIB_00        0x88

/* DEFINE REGISTERS VALUE */
#define BMP280_CHIP_ID         0x58
#define BMP280_RESET_VALUE     0xB6
/* CTRL MEAS */
#define BMP280_TEMP_OFF        0x00 << 5
#define BMP280_TEMP_16BIT      0x01 << 5
#define BMP280_TEMP_17BIT      0x02 << 5
#define BMP280_TEMP_18BIT      0x03 << 5
#define BMP280_TEMP_19BIT      0x04 << 5
#define BMP280_TEMP_20BIT      0x05 << 5
#define BMP280_TEMP_20BIT      0x06 << 5
#define BMP280_TEMP_20BIT      0x07 << 5

#define BMP280_PRESS_OFF       0x00 << 2
#define BMP280_PRESS_16BIT     0x01 << 2
#define BMP280_PRESS_17BIT     0x02 << 2
#define BMP280_PRESS_18BIT     0x03 << 2
#define BMP280_PRESS_19BIT     0x04 << 2
#define BMP280_PRESS_20BIT     0x05 << 2

#define BMP280_POWER_SLEEP     0x00
#define BMP280_POWER_FORCED_A  0x01
#define BMP280_POWER_FORCED_B  0x02
#define BMP280_POWER_NORMAL    0x03 

#endif //_BMP280_H_

void bmp280_init(void);
void bmp280_getTemperature(void);
void bmp280_getPressure(void);