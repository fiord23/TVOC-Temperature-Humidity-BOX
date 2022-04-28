#include "BMP280.h"
void bmp280_init(void)
{
  i2c1_read (BMP280_ADDRESS, BMP280_ID);
}

