//init I2C1 c
#include "main.h"          
#include "I2C1.h"
//PB8 SCL, PB9 SDA

void i2c1_init (void)
{
  //------------------------SET GPIO FOR I2C1--------------------------
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN_Msk << RCC_AHB1ENR_GPIOBEN_Pos; //set clocks for GPIOB 
  GPIOB->MODER &=~ (3 << GPIO_MODER_MODER8_Pos | 3 << GPIO_MODER_MODER9_Pos ); //RESET PB8, PB9 AF must be 0x2
  GPIOB->MODER |= (2 << GPIO_MODER_MODER8_Pos | 2 << GPIO_MODER_MODER9_Pos ); //SET PB8, PB9 AF I2C1
  GPIOB->AFR[1] |= (4 << GPIO_AFRH_AFSEL8_Pos | 4 << GPIO_AFRH_AFSEL9_Pos ); // SET I2C1 AFR  must be 0x4
  GPIOB->OSPEEDR &=~ (3 << GPIO_OSPEEDR_OSPEED8_Pos | 3 << GPIO_OSPEEDR_OSPEED9_Pos ); //RESET Spees Register
  GPIOB->OSPEEDR |= (3 << GPIO_OSPEEDR_OSPEED8_Pos | 3 << GPIO_OSPEEDR_OSPEED9_Pos ); // SET VERY HIGH SPEED must be 0x3
  GPIOB->IDR &=~ (1 << GPIO_IDR_ID8_Pos | 1 << GPIO_IDR_ID9_Pos ); //RESET IDR
  GPIOB->IDR |= (1 << GPIO_IDR_ID8_Pos | 1 << GPIO_IDR_ID9_Pos ); // SET PB8 anb PB9 to input must be 0x1
  
  //-------------------SET I2C1 CONFIG----------------------------------
  
}
