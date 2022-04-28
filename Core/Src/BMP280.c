#include "BMP280.h"
#include <stdio.h>
    
void bmp280_init(void)
{
  
  i2c1_write (BMP280_ADDRESS, BMP280_RESET, BMP280_RESET_VALUE);
  uint8_t tmp = 0;
  tmp = i2c1_read (BMP280_ADDRESS, BMP280_ID);
  char string[17] = {0};
  if (tmp == BMP280_CHIP_ID)
    {
    LCD_SetPos(0,0);
    LCD_String("BMP = OK"); 
    }
  else 
    {
    LCD_SetPos(0,0);
    LCD_String("BMP = ERROR"); 
    }
  i2c1_write (BMP280_ADDRESS, BMP280_CTRL_MEAS, BMP280_TEMP_16BIT | BMP280_PRESS_OFF | BMP280_POWER_NORMAL);
}

void bmp280_getTemperature(void)
{
   char string[17] = {0};
   uint8_t data[8] = {0};
   double var1= 0;
   double var2 = 0;
   double t_fine = 0;
   signed long temp280 = 0;
   unsigned short dig_T1 = 0;
   short dig_T2 = 0, dig_T3 =0;
  
    data[0] =i2c1_read (BMP280_ADDRESS, BMP280_TEMP_MSB);
    data[1] =i2c1_read (BMP280_ADDRESS, BMP280_TEMP_LSB);
    temp280 = (data[0] <<12 | data[1] << 4);

    data[2] = i2c1_read (BMP280_ADDRESS, BMP280_CALIB_01);
    data[3] = i2c1_read (BMP280_ADDRESS, BMP280_CALIB_00);
    dig_T1 = (data[2] <<8 | data[3]);

    data[4] = i2c1_read (BMP280_ADDRESS, BMP280_CALIB_03);
    data[5] = i2c1_read (BMP280_ADDRESS, BMP280_CALIB_02);
    dig_T2 = (data[4] <<8 | data[5]);

    data[6] = i2c1_read (BMP280_ADDRESS, BMP280_CALIB_05);
    data[7] = i2c1_read (BMP280_ADDRESS, BMP280_CALIB_04);
    dig_T3 = (data[6] <<8 | data[7]);


    var1 = (((double)temp280)/16384.0 - ((double)dig_T1)/1024.0)*((double)dig_T2);
    var2= ((((double)temp280)/131072.0 - ((double)dig_T1)/8192.0)*(((double)temp280)/131072.0 - ((double)dig_T1)/8192.0))*((double)dig_T3);
    t_fine = (var1+var2)/5120.0;
   sprintf (string, "i = %0.4f", t_fine);
   LCD_SetPos(1,1);
   LCD_String(string);
}
   


