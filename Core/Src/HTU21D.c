#include "HTU21D.h"
#include <stdio.h>

void htu21d_getTemperature(void)
{
   char string[17] = {0};
   uint8_t data_t[8] = {0};
  data_t[0] = i2c1_read (HTU21D_ADDRESS, HTU21D_TEMPERATURE_MEAS_HOLD);
   
}