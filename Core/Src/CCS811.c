#include "CCS811.h"

#define I2CXC I2C1
I2C_HandleTypeDef  hi2cxc;
uint8_t reset[] = {0x11, 0xE5, 0x72, 0x8A};
//uint8_t reset[] = {0x11, 0xE5, 0x72, 0x8A};
//uint8_t data1[10];   

//uint8_t meas[] = {0x40};
//uint8_t start[] = {0xF4, 0x00};

void CCS811_ini (void)
    {
//HAL_I2C_Mem_Read( &hi2c1, TVOC_Adress, HW_ID, 1, data1, 1,300);
  


//datat =i2c1_read (BMP280_ADDRESS, 0xD0);
//datat =i2c1_read (BMP280_ADDRESS, 0xF4);
//i2c1_write (TVOC_Adress, APP_START_REG1, 0x00);
//datat =i2c1_read (TVOC_Adress, APP_START_REG1);
//datat =i2c1_read (TVOC_Adress, STATUS);
//i2c1_write2 (TVOC_Adress, MEAS_MODE, 0x40);
//i2c1_write_some_bytes(TVOC_Adress, SW_RESET, reset, 4);
//datat =i2c1_read (TVOC_Adress, STATUS);
//i2c1_write_some_bytes(TVOC_Adress, SW_RESET, reset, 4);
//datat =i2c1_read (TVOC_Adress, STATUS);

//datat =i2c1_read (TVOC_Adress, HW_ID);

//datat =i2c1_read (TVOC_Adress, MEAS_MODE);
//datat =i2c1_read (TVOC_Adress, HW_ID);
//i2c1_read_some_bytes (TVOC_Adress, ALG_RESULT_DATA, data1 , 8 );
//datat =i2c1_read (TVOC_Adress, HW_ID);

      /*
          HAL_I2C_Mem_Write( &hi2c1, TVOC_Adress, SW_RESET, 1, reset, 4,300);
        HAL_Delay(100); 
        HAL_I2C_Mem_Read( &hi2c1, TVOC_Adress, HW_ID, 1, data1, 1,300);
         HAL_Delay(100); 
        HAL_I2C_Mem_Read( &hi2c1, TVOC_Adress, STATUS, 1, data1, 1,300);
         HAL_Delay(100); 
         HAL_I2C_Master_Transmit(&hi2c1, TVOC_Adress, &APP_START_REG1_1, 1, 100);  
         
      //  HAL_I2C_Mem_Write( &hi2c1, TVOC_Adress, APP_START_REG1, 1, empty, 0,1000);
        // HAL_Delay(100); 
        HAL_I2C_Mem_Read( &hi2c1, TVOC_Adress, STATUS, 1, data1, 1,300);
         HAL_Delay(100); 
        HAL_I2C_Mem_Write( &hi2c1, TVOC_Adress, MEAS_MODE, 1, meas, 1,300);
         HAL_Delay(100); 
        HAL_I2C_Mem_Read( &hi2c1, TVOC_Adress, STATUS, 1, data1, 1,300);
         HAL_Delay(100); 
        HAL_I2C_Mem_Read( &hi2c1, TVOC_Adress, MEAS_MODE, 1, data1, 1,300);
         HAL_Delay(100); 
        HAL_I2C_Mem_Read( &hi2c1, TVOC_Adress, ALG_RESULT_DATA, 1, data1, 8,300);  
         HAL_Delay(100);        
  // CCS811_ini ();
*/
    }



uint16_t eco2_get_data(void)
      {            
           uint8_t data12[2];
           uint16_t eco2_data;             
           HAL_I2C_Mem_Read( &hi2cxc, TVOC_Adress, ALG_RESULT_DATA, 1, data12, 8,300);
           eco2_data = (((uint8_t)data12[0]<<8)|((uint8_t)data12[1]<<0));
           HAL_Delay(500); 
           return (uint16_t)eco2_data;             
       }