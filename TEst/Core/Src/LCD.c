/*
 * LCD.c
 *
 *  Created on: Nov 1, 2024
 *      Author: Genki
 */
#include "LCD.h"
#include "string.h"
#include "stdio.h"
#include "main.h"
#include "stm32f4xx_hal.h"
#define addr_pcf8574 0x27 << 1
extern I2C_HandleTypeDef hi2c1;

void LCD_I2C_Write_CMD(uint8_t data){
	uint8_t buffer[4] = {(data & 0xF0) | 0x04 ,(data & 0xF0) | 0x00, (data << 4) | 0x04, (data << 4) | 0x00 };
	HAL_I2C_Master_Transmit(&hi2c1, addr_pcf8574, buffer, 4, HAL_MAX_DELAY);
}
void LCD_I2C_Write_DATA(uint8_t data){
	uint8_t buffer[4] = {(data & 0xF0) | 0x05 ,(data & 0xF0) | 0x01, (data << 4) | 0x05, (data << 4) | 0x01 };
	HAL_I2C_Master_Transmit(&hi2c1, addr_pcf8574, buffer, 4, HAL_MAX_DELAY);
}
void LCD_I2C_Init(void){
	LCD_I2C_Write_CMD(0x33);		//Khoi tao
	LCD_I2C_Write_CMD(0x32);		//Khoi tao
	LCD_I2C_Write_CMD(0x28);		//Che do 4 bit, 2 hang
	LCD_I2C_Write_CMD(0x0C);		//Hien thi man hinh, tat con tro
	LCD_I2C_Write_CMD(0x06);		//Tang con tro
	LCD_I2C_Write_CMD(0x01);		//Xoa man hinh
	HAL_Delay(2);					// Delay de xoa man hinh, ham khac thuc hien nhanh nen khong can Delay
}
void LCD_I2C_Clear(void){
	LCD_I2C_Write_CMD(0x01);
	HAL_Delay(2);
}
void LCD_I2C_Location(uint8_t x, uint8_t y){
	if(x == 0){
		LCD_I2C_Write_CMD(0x80+y);
	}
	else if(x == 1){
		LCD_I2C_Write_CMD(0xC0+y);
	}
}
void LCD_I2C_Write_String(char* string){
	for(uint8_t i = 0; i < strlen(string); i++){
		LCD_I2C_Write_DATA(string[i]);
	}
}
void LCD_I2C_Write_Number(int number){
	char buffer[8];
	sprintf(buffer, "%d", number);
	LCD_I2C_Write_String(buffer);
}

