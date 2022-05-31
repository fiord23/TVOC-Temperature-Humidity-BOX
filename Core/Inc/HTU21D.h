#include "stdint.h"
#ifndef _HTU21D_H_
#define _HTU21D_H_

#define HTU21D_ADDRESS                          0x40<<1

#define HTU21D_TEMPERATURE_MEAS_HOLD            0xE3
#define HTU21D_HUMIDITY_MEAS_HOLD               0xE5
#define HTU21D_TEMPERATURE_MEAS_NO_HOLD         0xF3
#define HTU21D_HUMIDITY_MEAS_HOLD               0xF5
#define HTU21D_WRITE_USER_REGISTER              0xE6
#define HTU21D_READ_USER_REGISTER               0xE7
#define HTU21D_SOFT_RESET                       0xFE
#endif

void htu21d_getTemperature();