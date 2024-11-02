/*
 * LCD.h
 *
 *  Created on: Nov 1, 2024
 *      Author: Genki
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_
#include "stm32f4xx_hal.h"

void LCD_I2C_Write_CMD(uint8_t data);

void LCD_I2C_Write_DATA(uint8_t data);

void LCD_I2C_Init(void);

void LCD_I2C_Clear(void);

void LCD_I2C_Location(uint8_t x, uint8_t y);

void LCD_I2C_Write_String(char* string);

void LCD_I2C_Write_Number(int number);


#endif /* INC_LCD_H_ */
