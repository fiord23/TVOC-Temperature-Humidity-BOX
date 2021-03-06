//init I2C1 c
#include "main.h"          
#include "I2C1.h"
//PB8 SCL, PB9 SDA

void i2c1_init (void)
{
  //------------------------SET GPIO FOR I2C1--------------------------
  RCC->AHB1ENR |= 1 << RCC_AHB1ENR_GPIOBEN_Pos; //set clocks for GPIOB 
  GPIOB->MODER &=~ (3 << GPIO_MODER_MODER8_Pos | 3 << GPIO_MODER_MODER9_Pos ); //RESET PB8, PB9 AF must be 0x2
  GPIOB->MODER |= (2 << GPIO_MODER_MODER8_Pos | 2 << GPIO_MODER_MODER9_Pos ); //SET PB8, PB9 AF I2C1
  GPIOB->AFR[1] |= (4 << GPIO_AFRH_AFSEL8_Pos | 4 << GPIO_AFRH_AFSEL9_Pos ); // SET I2C1 AFR  must be 0x4
  GPIOB->OSPEEDR &=~ (3 << GPIO_OSPEEDR_OSPEED8_Pos | 3 << GPIO_OSPEEDR_OSPEED9_Pos ); //RESET Spees Register
  GPIOB->OSPEEDR |= (3 << GPIO_OSPEEDR_OSPEED8_Pos | 3 << GPIO_OSPEEDR_OSPEED9_Pos ); // SET VERY HIGH SPEED must be 0x3
  GPIOB->IDR &=~ (1 << GPIO_IDR_ID8_Pos | 1 << GPIO_IDR_ID9_Pos ); //RESET IDR
  GPIOB->IDR |= (1 << GPIO_IDR_ID8_Pos | 1 << GPIO_IDR_ID9_Pos ); // SET PB8 anb PB9 to input must be 0x1
  
  //-------------------SET I2C1 CONFIG----------------------------------
    
  RCC->APB1ENR |= (1 <<RCC_APB1ENR_I2C1EN_Pos); //Enable I2C1 clock
  HAL_Delay(1);
  I2C1->CR1 &=~ (1 << I2C_CR1_PE_Pos);//PE = 0 disable periphera
  I2C1->CCR |= (0x0e1 << I2C_CCR_CCR_Pos);//Clock control Register CCR 0x0e1
  I2C1->CR2 |= (0x2d << I2C_CR2_FREQ_Pos);//Set frequency0x2d
  
  I2C1->TRISE |= (0x2e << I2C_TRISE_TRISE_Pos);//TRISE =0x2e
  I2C1->OAR2 &=~ (1 << I2C_OAR2_ENDUAL_Pos);  //clear double addressation
  I2C1->CR1 &=~ (1 << I2C_CR1_ENGC_Pos);  //clear General Call
   I2C1->CR1 &=~ (1 << FMPI2C_CR1_NOSTRETCH_Pos);  //clear General Call
   I2C1->CR1 &=~ (1 << I2C_CR1_PE_Pos);//PE = 0 disable periphera
   
   
   
    NVIC_SetPriority(I2C1_ER_IRQn, 0); //Set interrupt Error priority 0
  NVIC_SetPriority(I2C1_EV_IRQn, 1);// Set interrupt Event to 1
  NVIC_EnableIRQ(I2C1_ER_IRQn); //Enable Interrupt error
  NVIC_EnableIRQ(I2C1_EV_IRQn); // Enable Interrupt Event
  I2C1->CR1 |= (1 << I2C_CR1_PE_Pos);//PE = 1 enable periphera
  I2C1->CR1 |= (1 << I2C_CR1_ACK_Pos); // enable ACK
  

  
}

uint8_t i2c1_read (uint8_t address, uint8_t reg )
{
  //----write address and target reigster------
  I2C1->CR1 &=~ (1 <<  I2C_CR1_POS_Pos);
   I2C1->CR1 |= (1 << I2C_CR1_ACK_Pos); // enable ACK
  I2C1->CR1 |= (1 << I2C_CR1_START_Pos); //Set the start bit
  while(!(I2C1->SR1 & I2C_SR1_SB)) {}; 
  uint8_t b;
  I2C1->SR1; //read Status register for clear SB
  I2C1->DR = (address) + 0; //+1 for read, 0  for write  WRITING TARGET ADDRESS
  while(!(I2C1->SR1 & I2C_SR1_ADDR)) 
  { }; //Clearing ADDR 
  I2C1->SR1; //read SR1
  I2C1->SR2;  // read SR2
  I2C1->DR = reg; // write target register to DR
  while(!(I2C1->SR1 & I2C_SR1_TXE)) 
  { }; 
   //wait while tx not empty
  I2C1->CR1 |= (1 << I2C_CR1_START_Pos); //Set the start bit
//  I2C1->CR1 |= (1 << I2C_CR1_STOP_Pos); // Stop Bit
 
  
  //-----Write address and read data from target register------
 //   I2C1->CR1 |= (1 << I2C_CR1_START_Pos); //Set the start bit
  while(!(I2C1->SR1 & I2C_SR1_SB));
  I2C1->SR1;  //read Status register for clear SB
  
  I2C1->DR = (address)+1; //+1 for read, 0  for write //wite address of target device +1 for read data
  while(!(I2C1->SR1 & I2C_SR1_ADDR)); //Clearing ADDR 
  I2C1->SR1; //read SR1
  I2C1->SR2; // read SR2
  I2C1->CR1 &=~ (1 << I2C_CR1_ACK_Pos); // clear ACK
  I2C1->CR1 |= (1 << I2C_CR1_STOP_Pos); // Stop Bit
  //while(!(I2C1->SR1 & I2C_SR1_TXE));
   while(!(I2C1->SR1 & I2C_SR1_RXNE));
  b = I2C1->DR;
  
  return b;
}

void i2c1_read_some_bytes (uint8_t address, uint8_t reg, uint8_t* regdata, uint8_t quantity )
{
  //----write address and target reigster------
  I2C1->CR1 |= (1 << I2C_CR1_START_Pos); //Set the start bit
  //while(!(I2C1->SR2 & I2C_SR2_BUSY)); 
  while(!(I2C1->SR1 & I2C_SR1_SB)); 
  uint8_t a =0 ; //temp value
  uint8_t b;
  a = I2C1->SR1; //read Status register for clear SB
  I2C1->DR = (address) + 0; //+1 for read, 0  for write  WRITING TARGET ADDRESS
  while(!(I2C1->SR1 & I2C_SR1_ADDR)); //Clearing ADDR 
  a = I2C1->SR1; //read SR1
  a = I2C1->SR2;  // read SR2
  while(!(I2C1->SR1 & I2C_SR1_TXE)); //wait while tx not empty
  I2C1->DR = reg; // write target register to DR
  I2C1->CR1 |= (1 << I2C_CR1_STOP_Pos); // Stop Bit
 
  //-----Write address and read data from target register------
    I2C1->CR1 |= (1 << I2C_CR1_START_Pos); //Set the start bit
  while(!(I2C1->SR1 & I2C_SR1_SB));
  a = I2C1->SR1;  //read Status register for clear SB
  I2C1->DR = (address)+1; //+1 for read, 0  for write //wite address of target device +1 for read data
  while(!(I2C1->SR1 & I2C_SR1_ADDR)); //Clearing ADDR 
  a = I2C1->SR1; //read SR1
  a = I2C1->SR2; // read SR2
  
   while(!(I2C1->SR1 & I2C_SR1_RXNE));
   
  
   for (int i =0; i <quantity-2; i ++)
  {
   //  I2C1->CR1 &=~ (1 << I2C_CR1_ACK_Pos);
    *regdata= I2C1->DR;
   
    regdata++;  
    //while(!(I2C1->SR1 & I2C_SR1_RXNE));
  }
  I2C1->CR1 &=~ (1 << I2C_CR1_ACK_Pos);
  *regdata= I2C1->DR;
  regdata++;  
    I2C1->CR1 |= (1 << I2C_CR1_ACK_Pos);
  *regdata= I2C1->DR;
  I2C1->CR1 |= (1 << I2C_CR1_STOP_Pos); // Stop Bit
  //return *arret;
  
}




void i2c1_writex (uint8_t address, uint8_t reg, uint8_t regdata )
{
   //while(!(I2C1->SR2 & I2C_SR2_BUSY)); 
  I2C1->CR1 &=~ (1 << I2C_CR1_POS_Pos); // Disable Pos
   I2C1->CR1 |= (1 << I2C_CR1_ACK_Pos); // Set ACK
  //----write address and target reigster------
  I2C1->CR1 |= (1 << I2C_CR1_START_Pos); //Set the start bit
  while(!(I2C1->SR1 & I2C_SR1_SB)){}; 
  I2C1->SR1; //read Status register for clear SB
  I2C1->DR = (address) + 0; //+1 for read, 0  for write  WRITING TARGET ADDRESS
  while(!(I2C1->SR1 & I2C_SR1_ADDR)) {}; //Clearing ADDR 
  I2C1->SR1; //read SR1
  I2C1->SR2;  // read SR2
   I2C1->DR = reg; // write target register to DR
  while(!(I2C1->SR1 & I2C_SR1_TXE)) {};
  I2C1->DR = regdata;
   while(!(I2C1->SR1 & I2C_SR1_TXE)) {};
  //while(!(I2C1->SR1 & I2C_SR1_TXE)); //wait while tx not empty

  
 // while(!(I2C1->SR1 & I2C_SR1_BTF)); 
 I2C1->CR1 |= (1 << I2C_CR1_STOP_Pos); // Stop Bit
}

void i2c1_write (uint8_t address, uint8_t reg, uint8_t regdata )
{
   //while(!(I2C1->SR2 & I2C_SR2_BUSY)); 
  I2C1->CR1 &=~ (1 << I2C_CR1_POS_Pos); // Disable Pos
   I2C1->CR1 |= (1 << I2C_CR1_ACK_Pos); // Set ACK
  //----write address and target reigster------
  I2C1->CR1 |= (1 << I2C_CR1_START_Pos); //Set the start bit
  while(!(I2C1->SR1 & I2C_SR1_SB)){}; 
  I2C1->SR1; //read Status register for clear SB
  I2C1->DR = (address) + 0; //+1 for read, 0  for write  WRITING TARGET ADDRESS
  while(!(I2C1->SR1 & I2C_SR1_ADDR)) { }; //Clearing ADDR 
  I2C1->SR1; //read SR1
  I2C1->SR2;  // read SR2 
   I2C1->DR = reg; // write target register to DR
  while(!(I2C1->SR1 & I2C_SR1_TXE))  {  };
  I2C1->DR = regdata;
  while(!(I2C1->SR1 & I2C_SR1_TXE))  {};
  I2C1->CR1 |= (1 << I2C_CR1_STOP_Pos); // Stop Bit
}





void i2c1_write_some_bytes (uint8_t address, uint8_t reg, uint8_t* regdata, uint8_t quantity )
{
  //----write address and target reigster------
   //while(!(I2C1->SR2 & I2C_SR2_BUSY)); 
  I2C1->CR1 &=~ (1 << I2C_CR1_POS_Pos); // Disable Pos
   I2C1->CR1 |= (1 << I2C_CR1_ACK_Pos); // Set ACK
  //----write address and target reigster------
  I2C1->CR1 |= (1 << I2C_CR1_START_Pos); //Set the start bit
  while(!(I2C1->SR1 & I2C_SR1_SB)){}; 
  I2C1->SR1; //read Status register for clear SB
  I2C1->DR = (address) + 0; //+1 for read, 0  for write  WRITING TARGET ADDRESS
  while(!(I2C1->SR1 & I2C_SR1_ADDR)) {}; //Clearing ADDR 
  I2C1->SR1; //read SR1
  I2C1->SR2;  // read SR2 
   I2C1->DR = reg; // write target register to DR
//  while(!(I2C1->SR1 & I2C_SR1_BTF));
  
  for (int i =0; i <quantity; i ++)
  {
    I2C1->DR = regdata[i];
    while(!(I2C1->SR1 & I2C_SR1_TXE)) {} ;     
  }  
 I2C1->CR1 |= (1 << I2C_CR1_STOP_Pos); // Stop Bit
}


