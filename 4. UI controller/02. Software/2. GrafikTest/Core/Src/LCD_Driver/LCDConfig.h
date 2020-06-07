/*
 * LCDConfig.h
 *
 *  Created on: May 31, 2020
 *      Author: marcel
 */

#ifndef SRC_LCD_DRIVER_LCDCONFIG_H_
#define SRC_LCD_DRIVER_LCDCONFIG_H_

#include "stm32f3xx_hal.h"

#define LCD_WRITE_DATA	HAL_GPIO_WritePin(WR_GPIO_Port, WR_Pin, GPIO_PIN_RESET);HAL_GPIO_WritePin(RD_GPIO_Port, RD_Pin, GPIO_PIN_SET)
#define LCD_READ_DATA	HAL_GPIO_WritePin(WR_GPIO_Port, WR_Pin, GPIO_PIN_SET);HAL_GPIO_WritePin(RD_GPIO_Port, RD_Pin, GPIO_PIN_RESET)

#define LCD_ENABLE		HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, GPIO_PIN_RESET)
#define LCD_DISABLE		HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, GPIO_PIN_SET)

#define LCD_RW_COMMAND 	HAL_GPIO_WritePin(CD_GPIO_Port, CD_Pin, GPIO_PIN_SET)
#define LCD_RW_DATA 	HAL_GPIO_WritePin(CD_GPIO_Port, CD_Pin, GPIO_PIN_RESET)

#define LCD_RST_L		HAL_GPIO_WritePin(RST_GPIO_Port, RST_Pin, GPIO_PIN_RESET)
#define	LCD_RST_H		HAL_GPIO_WritePin(RST_GPIO_Port, RST_Pin, GPIO_PIN_SET)

#define LCD_FONT_68		HAL_GPIO_WritePin(RST_GPIO_Port, RST_Pin, GPIO_PIN_SET)
#define LCD_FONT_88		HAL_GPIO_WritePin(RST_GPIO_Port, RST_Pin, GPIO_PIN_RESET)


//Command define

#define LCD_setCursorPointer					0x21
#define LCD_setOffsetRegister					0x22
#define LCD_setAddressPointer					0x24

#define LCD_setTextHomeAddress					0x40
#define LCD_setTextArea							0x41
#define LCD_setGraphicHomeAddress				0x42
#define LCD_setGraphicArea						0x43

#define LCD_OR_mode								0x80
#define LCD_EXOR_mode							0x81
#define LCD_AND_mode							0x83
#define LCD_TextAtribute_mode					0x84
#define LCD_InternalCGROM_mode					0x80
#define LCD_externalCGRAM_mode					0x88

#define LCD_DisplayOFF							0x90
#define LCD_cursorOnBlinkOff					0x92
#define LCD_cursorOnBlinkON						0x93
#define LCD_textOnGraphicOFF					0x94
#define LCD_textOFFGraphicON					0x98
#define LCD_textONGraphicON						0x9C

#define LCD_1_lineCursor						0xA
#define LCD_2_lineCursor						0xA1
#define LCD_3_lineCursor						0xA2
#define LCD_4_lineCursor						0xA3
#define LCD_5_lineCursor						0xA4
#define LCD_6_lineCursor						0xA5
#define LCD_7_lineCursor						0xA6
#define LCD_8_lineCursor						0xA7

#define LCD_setDataAutoWrite					0xB0
#define LCD_setDataAutoRead						0xB1
#define LCD_autoReset							0xB2

#define LCD_dataWriteAndIncrementADP			0xC0
#define LCD_dataReadAndIncrementADP				0xC1
#define LCD_dataWriteAndDecrementADP			0xC2
#define LCD_dataReadAndDecrementADP				0xC3
#define LCD_dataWriteandNonvariableADP			0xC4
#define LCD_dataReadAndNonvariableADP			0xC5

#define LCD_screenPeek							0xE0
#define LCD_screenCopy							0xE8

#define LCD_bitReset							0xF0
#define LCD_bitSet								0xF8
#define LCD_bit0								0xF0
#define LCD_bit1								0xF1
#define LCD_bit2								0xF2
#define LCD_bit3								0xF3
#define LCD_bit4								0xF4
#define LCD_bit5								0xF5
#define LCD_bit6								0xF6
#define LCD_bit7								0xF7



#endif /* SRC_LCD_DRIVER_LCDCONFIG_H_ */
