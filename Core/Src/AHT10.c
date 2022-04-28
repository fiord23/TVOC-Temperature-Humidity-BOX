//AHT CONFIG
// uint8_t AHT10_RX_Data[6];
//uint32_t AHT10_ADC_Raw;
float AHT10_Temperature;
float AHT10_Humidity;
int AHT10_Temperature_int[2];
int AHT10_Humidity_int[2];
//uint8_t AHT10_TmpHum_Cmd = 0xAC; 


    /*
    HAL_I2C_Mem_Read( &hi2c1, TVOC_Adress, ALG_RESULT_DATA, 1, data, 8,300);
    eco2_data = ((data[0]<<8)|(data[1]<<0));
 



HAL_I2C_Master_Transmit(&hi2c1, AHT10_Adress, &AHT10_TmpHum_Cmd, 1, 100);
HAL_Delay(100); // Delay must be > 75 ms
HAL_I2C_Master_Receive(&hi2c1, AHT10_Adress, (uint8_t*)AHT10_RX_Data, 6, 100);

AHT10_ADC_Raw = (((uint32_t)AHT10_RX_Data[3] & 15) << 16) | ((uint32_t)AHT10_RX_Data[4] << 8) | AHT10_RX_Data[5];
AHT10_Temperature = (float)(AHT10_ADC_Raw * 200.00 / 1048576.00) - 50.00;
AHT10_ADC_Raw = ((uint32_t)AHT10_RX_Data[1] << 12) | ((uint32_t)AHT10_RX_Data[2] << 4) | (AHT10_RX_Data[3] >> 4);
AHT10_Humidity = (float)(AHT10_ADC_Raw*100.00/1048576.00);
HAL_Delay(1000);  
    
AHT10_Temperature_int[0] = (int)AHT10_Temperature;
AHT10_Temperature_int[1]  = ((int) (AHT10_Temperature*100)%100);

AHT10_Humidity_int[0] = (int)AHT10_Humidity;
AHT10_Humidity_int[1]  = ((int) (AHT10_Humidity*100)%100);


    LCD_SetPos(0,0);
    LCD_String(co2);

    LCD_SendChar((eco2_data/10000)%10 + 0x30);
    LCD_SendChar((eco2_data/1000)%10 + 0x30);
    LCD_SendChar((eco2_data/100)%10 + 0x30);
    LCD_SendChar((eco2_data/10)%10 + 0x30);
    LCD_SendChar((eco2_data)%10 + 0x30);
    
    
    voc_data = ((data[2]<<8)|(data[3]<<0));
     LCD_SetPos(9,0);
    LCD_String(voc);
  
    LCD_SendChar((voc_data/1000)%10 + 0x30); 
    LCD_SendChar((voc_data/100)%10 + 0x30);
    LCD_SendChar((voc_data/10)%10 + 0x30);
    LCD_SendChar((voc_data)%10 + 0x30);

    
    LCD_SetPos(0,1);
    LCD_String(tem);
    LCD_SendChar((AHT10_Temperature_int[0]/10)%10 + 0x30);
    LCD_SendChar((AHT10_Temperature_int[0])%10 + 0x30);
    LCD_SendChar('.');
    LCD_SendChar((AHT10_Temperature_int[1]/10)%10 + 0x30);
    LCD_SendChar((AHT10_Temperature_int[1])%10 + 0x30);
    
    LCD_SetPos(9,1);
    LCD_String(hum);
    LCD_SendChar((AHT10_Humidity_int[0]/10)%10 + 0x30);
    LCD_SendChar((AHT10_Humidity_int[0])%10 + 0x30);
    LCD_SendChar('.');
    LCD_SendChar((AHT10_Humidity_int[1]/10)%10 + 0x30);
    LCD_SendChar((AHT10_Humidity_int[1])%10 + 0x30);
HAL_Delay(500);

*/
