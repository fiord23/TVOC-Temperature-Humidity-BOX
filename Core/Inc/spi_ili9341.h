#ifndef __SPI_ILI9341_H
#define __SPI_ILI9341_H
//-------------------------------------------------------------------
#include "stm32l4xx_hal.h"
#define d4_set() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET)
#define d5_set() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET)
#define d6_set() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET)
#define d7_set() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET)

#define d4_reset() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET)
#define d5_reset() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET)
#define d6_reset() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET)
#define d7_reset() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET)

 

#define e1    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET) // Enable to 1

#define e0    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET) //Enable to 0

#define rs1   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET) // RS to 1

#define rs0   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET) // RS 0

void LCD_ini(void);
void LCD_WriteData(uint8_t dt);
void delay(void);
void LCD_Command(uint8_t dt);
void LCD_Data(uint8_t dt);
void LCD_Clear(void);
void LCD_SendChar(char ch);
void LCD_String(char* st);
void LCD_SetPos(uint8_t x, uint8_t y);
//-------------------------------------------------------------------
#endif /* __SPI_ILI9341_H */

