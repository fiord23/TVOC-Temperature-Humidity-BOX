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
  RCC->APB1ENR |= (1 <<RCC_APB1ENR_I2C1EN_Pos); //Enable I2C1 clock
  I2C1->CR2 |= (0x2d << I2C_CR2_FREQ_Pos);//Set frequency0x2d
  I2C1->CCR |= (0x0e1 << I2C_CCR_CCR_Pos);//Clock control Register CCR 0x0e1
  I2C1->TRISE |= (0x2e << I2C_TRISE_TRISE_Pos);//TRISE =0x2e
  I2C1->CR1 |= (1 << I2C_CR1_PE_Pos);//PE = 1 enable peripheral
  NVIC_SetPriority(I2C1_ER_IRQn, 0); //Set interrupt Error priority 0
  NVIC_SetPriority(I2C1_EV_IRQn, 1);// Set interrupt Event to 1
  NVIC_EnableIRQ(I2C1_ER_IRQn); //Enable Interrupt error
  NVIC_EnableIRQ(I2C1_EV_IRQn); // Enable Interrupt Event
  
}
