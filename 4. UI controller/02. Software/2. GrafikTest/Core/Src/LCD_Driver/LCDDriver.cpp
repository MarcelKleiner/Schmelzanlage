/*
 * LCDDriver.cpp
 *
 *  Created on: May 31, 2020
 *      Author: marcel
 */

#include "LCDDriver.h"
#include "LCDConfig.h"
#include "main.h"

LCDDriver::LCDDriver() {
	// TODO Auto-generated constructor stub

}


void LCDDriver::InitLCD(){
	Reset();


}


bool LCDDriver::WriteData_8bit(uint8_t addr, uint8_t data){
	CheckStatus(LCD_TIMEOUT);
	LCD_WRITE_DATA;
	LCD_ENABLE;
	LCD_RW_DATA;
	WriteDataPin(data);
	CheckStatus(LCD_TIMEOUT);
	LCD_WRITE_DATA;
	LCD_ENABLE;
	LCD_RW_COMMAND;
	WriteDataPin(addr);
	LCD_DISABLE;
}

bool LCDDriver::WriteData_16bit(uint8_t addr, uint16_t data){
	CheckStatus(LCD_TIMEOUT);
	LCD_WRITE_DATA;
	LCD_ENABLE;
	LCD_RW_DATA;
	WriteDataPin((uint8_t)data);
	CheckStatus(LCD_TIMEOUT);
	LCD_WRITE_DATA;
	LCD_ENABLE;
	LCD_RW_DATA;
	WriteDataPin((uint8_t)(data>>8));
	CheckStatus(LCD_TIMEOUT);
	LCD_WRITE_DATA;
	LCD_ENABLE;
	LCD_RW_COMMAND;
	WriteDataPin(addr);
	LCD_DISABLE;
}


/*
 * Checking LCD Status register
 *
 * @param timeOut: timeout for statuscheck
 * @return LCD_STATUS: lcdStatus Error / OK
 */
LCDDriver::LCD_STATUS LCDDriver::CheckStatus(uint8_t timeOut){
	LCD_READ_DATA;
	LCD_ENABLE;
	LCD_RW_DATA;
	uint8_t counter = timeOut;
	while(!(ReadDataPin() | 0x02) && counter != 0){
		HAL_Delay(1);
		counter--;
	}

	if(ReadDataPin() | 0x40 || counter == 0){
		LCD_DISABLE;
		return LCD_STATUS_ERROR;
	}else{
		LCD_DISABLE;
		return LCD_STATUS_OK;
	}
}

/*
 * Read dataport 0-7
 *
 * @param none
 * @return 8bit data from port 0-7 (msb first)
 */
uint8_t LCDDriver::ReadDataPin(){
	uint8_t data = 0;

	data |= HAL_GPIO_ReadPin(D7_GPIO_Port, D7_Pin);
	data = (data<<1) | HAL_GPIO_ReadPin(D6_GPIO_Port, D6_Pin);
	data = (data<<1) | HAL_GPIO_ReadPin(D5_GPIO_Port, D5_Pin);
	data = (data<<1) | HAL_GPIO_ReadPin(D4_GPIO_Port, D4_Pin);
	data = (data<<1) | HAL_GPIO_ReadPin(D3_GPIO_Port, D3_Pin);
	data = (data<<1) | HAL_GPIO_ReadPin(D2_GPIO_Port, D2_Pin);
	data = (data<<1) | HAL_GPIO_ReadPin(D1_GPIO_Port, D1_Pin);
	data = (data<<1) | HAL_GPIO_ReadPin(D0_GPIO_Port, D0_Pin);
	return data;
}

void LCDDriver::WriteDataPin(uint8_t data){
	HAL_GPIO_WritePin(D0_GPIO_Port, D0_Pin, (GPIO_PinState)(data & 0x00));
	HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, (GPIO_PinState)(data & 0x01));
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, (GPIO_PinState)(data & 0x04));
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, (GPIO_PinState)(data & 0x08));
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, (GPIO_PinState)(data & 0x10));
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, (GPIO_PinState)(data & 0x20));
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, (GPIO_PinState)(data & 0x40));
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, (GPIO_PinState)(data & 0x80));
}

/*
 * Reset LCD
 *
 * @param none
 * @return none
 */
void LCDDriver::Reset(){
	LCD_RST_L;
	HAL_Delay(1);
	LCD_RST_H;
}


