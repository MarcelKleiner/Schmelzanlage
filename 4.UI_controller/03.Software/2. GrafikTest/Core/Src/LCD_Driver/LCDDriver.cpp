/*
 * LCDDriver.cpp
 *
 *  Created on: May 31, 2020
 *      Author: marcel
 */

#include "LCDDriver.h"
#include "LCDConfig.h"
#include "main.h"
#include "i2c.h"
#include "gpio.h"
#include "stdlib.h"

LCDDriver::LCDDriver() {
	// TODO Auto-generated constructor stub

}


void LCDDriver::InitLCD(){
	Reset();
	LCD_RD_SET;
	LCD_WR_SET;
	SetLCDSize(SIZE_40C);

	//init REGISTERS SETTING
	WriteData_16bit(LCD_setCursorPointer,0);
	WriteData_16bit(LCD_setAddressPointer, 0);
	WriteData_16bit(LCD_setOffsetRegister, 0);
	//Init SET CONTROL WORD
	WriteData_16bit(LCD_setTextHomeAddress,0);
	WriteData_16bit(LCD_setGraphicHomeAddress, 0);
	//Init MODE SET
	WriteData_8bit(LCD_EXOR_mode |LCD_externalCGRAM_mode);
	//Init DISPLY MODE
	WriteData_8bit(LCD_cursorOnBlinkON | LCD_textONGraphicOFF);
	//Init CURSOR PATTERN SELECT
	WriteData_8bit(LCD_1_lineCursor);
	//Init DATA AUTO READ/WRITE
	WriteData_8bit(LCD_setDataAutoRead);
	//Init SCREEN REVERSE
	WriteData_16bit(LCD_SCREEN_REVERSE, NORMAL_DISPLAY);
	//Init BLINK TIME
	WriteData_16bit(LCD_BLINK_TIME, BLINK_TIM_0_066);
	//Init CURSOR AUTO MOVING
	WriteData_16bit(LCD_CursorAutoMoving, AUTO_MOVING_ON);


	SetAddressPointer(0, 0);
	ClearDisplay();

}


bool LCDDriver::WriteText(string data){
	uint16_t counter = 0;
	while(data[counter] != '\0'){
		WriteData_8bit(LCD_dataWriteAndIncrementADP,(uint8_t)data[counter]-32);
		counter++;
	}

	return true;
}







/*
 * Init the LCD Size (40 Columns / 32 Columns)
 *
 * @param size: LCD Size
 * @return : none
 */
void LCDDriver::SetLCDSize(LCD_SIZE size){
	if(size == SIZE_40C){
		LCD_SIZE_40;				//set size 40 Columns
		LCD_FONT_68;				//set Fontsize 6x8px
		LCD_XY_SIZE.column = 40;	//set LCD size struct to 40 Columns
		LCD_XY_SIZE.row = 16;		//set LCD size struct to 16 Row
		WriteData_16bit(LCD_setTextArea, 0x0028);	//set TextArea to 32 Columns
		WriteData_16bit(LCD_setGraphicArea, 0x0028);
	}
	else if(size == SIZE_32C){
		LCD_SIZE_32;				//set size 40 Columns
		LCD_FONT_88;				//set Fontsize 6x8px
		LCD_XY_SIZE.column = 32;	//set LCD size struct to 40 Columns
		LCD_XY_SIZE.row = 16;		//set LCD size struct to 16 Row
		WriteData_16bit(LCD_setTextArea, 0x0020);	//set TextArea to 40 Columns
		WriteData_16bit(LCD_setGraphicArea, 0x0020);
	}
}

/*
 * clears the whole LCD depending on the selected size
 *
 * @param  : none
 * @return : none
 */
void LCDDriver::ClearDisplay(){
	WriteData_16bit(LCD_setOffsetRegister, 0x0003);

	WriteData_16bit(LCD_setAddressPointer, 0x1C00);

	WriteData_8bit(LCD_dataWriteAndIncrementADP, 0x0000);
	WriteData_8bit(LCD_dataWriteAndIncrementADP, 0x0004);
	WriteData_8bit(LCD_dataWriteAndIncrementADP, 0x000E);
	WriteData_8bit(LCD_dataWriteAndIncrementADP, 0x0015);
	WriteData_8bit(LCD_dataWriteAndIncrementADP, 0x0004);
	WriteData_8bit(LCD_dataWriteAndIncrementADP, 0x0004);
	WriteData_8bit(LCD_dataWriteAndIncrementADP, 0x0004);
	WriteData_8bit(LCD_dataWriteAndIncrementADP, 0x0000);

	WriteData_16bit(LCD_setAddressPointer, 0x0000);
	for(uint16_t counter = 0; counter<LCD_XY_SIZE.column*LCD_XY_SIZE.row; counter++){
		WriteData_8bit(LCD_dataWriteAndIncrementADP, 0x80);
	}
}


/*
 * Set the AdressPointer to specific XY coordinates
 *
 * @param column: the chosen Column
 * @param row: the chosen Row
 * @return : none;
 */
void LCDDriver::SetAddressPointer(uint8_t column, uint8_t row){
	uint16_t LCDPointer = row*LCD_XY_SIZE.column + column;	//calculate the AdressPointer depending on the selected LCD Size
	WriteData_16bit(LCD_setAddressPointer, LCDPointer);		//set the AdressPointer
}


bool LCDDriver::WriteData_8bit(uint8_t addr){
	LCD_OUTPUT_ENABLE;


	if(CheckStatus(LCD_TIMEOUT) == LCD_STATUS_ERROR){
		return false;
	}
	WriteDataPin(addr);
	LCD_RW_COMMAND;
	PushData();

	LCD_OUTPUT_DISABLE;
	return true;
}


bool LCDDriver::WriteData_8bit(uint8_t addr, uint8_t data){
	LCD_OUTPUT_ENABLE;

	if(CheckStatus(LCD_TIMEOUT) == LCD_STATUS_ERROR){
		return false;
	}
	WriteDataPin(data);
	LCD_RW_DATA;
	PushData();

	if(CheckStatus(LCD_TIMEOUT) == LCD_STATUS_ERROR){
		return false;
	}
	WriteDataPin(addr);
	LCD_RW_COMMAND;
	PushData();

	LCD_OUTPUT_DISABLE;
	return true;
}

bool LCDDriver::WriteData_16bit(uint8_t addr, uint16_t data){
	LCD_OUTPUT_ENABLE;

	if(CheckStatus(LCD_TIMEOUT) == LCD_STATUS_ERROR){
		return false;
	}
	WriteDataPin((uint8_t)data);
	LCD_RW_DATA;
	PushData();

	if(CheckStatus(LCD_TIMEOUT) == LCD_STATUS_ERROR){
		return false;
	}
	WriteDataPin((uint8_t)(data>>8));
	LCD_RW_DATA;
	PushData();

	if(CheckStatus(LCD_TIMEOUT) == LCD_STATUS_ERROR){
		return false;
	}
	WriteDataPin(addr);
	LCD_RW_COMMAND;
	PushData();

	LCD_OUTPUT_DISABLE;
	return true;
}

void LCDDriver::PushData(){
	//toggle WR and Enable PIN so that the LCD reads the data
	LCD_WR_RESET;
	LCD_ENABLE;
	LCD_DISABLE;
	LCD_WR_SET;
}


/*
 * Checking LCD Status register
 *
 * @param timeOut: timeout for statuscheck
 * @return LCD_STATUS: lcdStatus Error / OK
 */
LCDDriver::LCD_STATUS LCDDriver::CheckStatus(uint8_t timeOut){
	GPIO_Direction(PIN_INPUT);

	LCD_ENABLE;
	LCD_RD_RESET;
	LCD_CD_SET;

	while(!(ReadDataPin() | 0x02) && timeOut != 0){
		HAL_Delay(1);
		timeOut--;
	}

	LCD_DISABLE;
	LCD_RD_SET;
	GPIO_Direction(PIN_OUTPUT);

	return timeOut != 0 ? LCD_STATUS_OK:LCD_STATUS_ERROR;
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


void LCDDriver::GPIO_Direction(PIN_DIRECTION pinDirection){
	GPIO_InitTypeDef GPIO_InitStruct_1 = {0};
	GPIO_InitTypeDef GPIO_InitStruct_2 = {0};
	GPIO_InitTypeDef GPIO_InitStruct_3 = {0};

	GPIO_InitStruct_1.Pull = GPIO_NOPULL;
	GPIO_InitStruct_1.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct_2.Pull = GPIO_NOPULL;
	GPIO_InitStruct_2.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct_3.Pull = GPIO_NOPULL;
	GPIO_InitStruct_3.Speed = GPIO_SPEED_FREQ_LOW;

	GPIO_InitStruct_1.Pin = D5_Pin|D4_Pin;
	GPIO_InitStruct_2.Pin = D7_Pin|D6_Pin|D0_Pin|D1_Pin;
	GPIO_InitStruct_3.Pin = D2_Pin|D3_Pin;


	if(pinDirection == PIN_INPUT){
		GPIO_InitStruct_1.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct_2.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct_3.Mode = GPIO_MODE_INPUT;
	}
	else if(pinDirection == PIN_OUTPUT){
		GPIO_InitStruct_1.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct_2.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct_3.Mode = GPIO_MODE_OUTPUT_PP;
	}

	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct_1);
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct_2);
	HAL_GPIO_Init(GPIOF, &GPIO_InitStruct_3);
}


void LCDDriver::WriteDataPin(uint8_t data){

	HAL_GPIO_WritePin(D0_GPIO_Port, D0_Pin, (GPIO_PinState)(data & 0x01));
	HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, (GPIO_PinState)(data & 0x02));
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


