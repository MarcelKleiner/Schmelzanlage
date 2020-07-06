/*
 * LCDConfig.h
 *
 *  Created on: May 31, 2020
 *      Author: marcel
 */

#ifndef SRC_LCD_DRIVER_LCDCONFIG_H_
#define SRC_LCD_DRIVER_LCDCONFIG_H_

#include "stm32f3xx_hal.h"

#define LCD_WR_SET		HAL_GPIO_WritePin(WR_GPIO_Port, WR_Pin, GPIO_PIN_SET)
#define LCD_WR_RESET	HAL_GPIO_WritePin(WR_GPIO_Port, WR_Pin, GPIO_PIN_RESET)

#define LCD_RD_SET		HAL_GPIO_WritePin(RD_GPIO_Port, RD_Pin, GPIO_PIN_SET)
#define LCD_RD_RESET	HAL_GPIO_WritePin(RD_GPIO_Port, RD_Pin, GPIO_PIN_RESET)

#define LCD_CD_SET	 	HAL_GPIO_WritePin(CD_GPIO_Port, CD_Pin, GPIO_PIN_SET)
#define LCD_CD_RESET 	HAL_GPIO_WritePin(CD_GPIO_Port, CD_Pin, GPIO_PIN_RESET)


#define LCD_WRITE_DATA	HAL_GPIO_WritePin(WR_GPIO_Port, WR_Pin, GPIO_PIN_RESET);HAL_GPIO_WritePin(RD_GPIO_Port, RD_Pin, GPIO_PIN_SET)
#define LCD_READ_DATA	HAL_GPIO_WritePin(WR_GPIO_Port, WR_Pin, GPIO_PIN_SET);HAL_GPIO_WritePin(RD_GPIO_Port, RD_Pin, GPIO_PIN_RESET)

#define LCD_ENABLE		HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, GPIO_PIN_RESET)
#define LCD_DISABLE		HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, GPIO_PIN_SET)

#define LCD_RW_COMMAND 	HAL_GPIO_WritePin(CD_GPIO_Port, CD_Pin, GPIO_PIN_SET)
#define LCD_RW_DATA 	HAL_GPIO_WritePin(CD_GPIO_Port, CD_Pin, GPIO_PIN_RESET)

#define LCD_RST_L		HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_RESET)
#define	LCD_RST_H		HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_SET)

#define LCD_FONT_68		HAL_GPIO_WritePin(FS_GPIO_Port, FS_Pin, GPIO_PIN_SET)
#define LCD_FONT_88		HAL_GPIO_WritePin(FS_GPIO_Port, FS_Pin, GPIO_PIN_RESET)

#define LCD_SIZE_32		HAL_GPIO_WritePin(MD2_GPIO_Port, MD2_Pin, GPIO_PIN_SET)
#define LCD_SIZE_40		HAL_GPIO_WritePin(MD2_GPIO_Port, MD2_Pin, GPIO_PIN_RESET)

#define LCD_OUTPUT_ENABLE		HAL_GPIO_WritePin(OE_GPIO_Port, OE_Pin, GPIO_PIN_SET)
#define LCD_OUTPUT_DISABLE		HAL_GPIO_WritePin(OE_GPIO_Port, OE_Pin, GPIO_PIN_RESET)


//digital Potentiometer
#define A0				0

#if A0 == 1
	#define POTI_ADDR		0x2F
#else
	#define POTI_ADDR		0x2E
#endif

#define POTI_STATUS_REG		0x05
#define POTI_TCON_REG		0x04
#define POTI_VWIPER0		0x00
#define POTI_VWIPER1		0x01
#define POTI_NVWIPER0		0x02
#define POTI_NVWIPER1		0x03


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
#define LCD_textONGraphicOFF					0x94
#define LCD_textOFFGraphicON					0x98
#define LCD_textONGraphicON						0x9C

#define LCD_1_lineCursor						0xA0
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
#define LCD_bit0								0x00
#define LCD_bit1								0x01
#define LCD_bit2								0x02
#define LCD_bit3								0x03
#define LCD_bit4								0x04
#define LCD_bit5								0x05
#define LCD_bit6								0x06
#define LCD_bit7								0x07

#define LCD_SCREEN_REVERSE						0xD0
#define LCD_BLINK_TIME							0x50
#define LCD_CursorAutoMoving					0x60
#define LCD_CGROM_FONT_SELECT					0x70

//DATA define

#define NORMAL_DISPLAY							0x00
#define REVERSE_DISPLAY							0x01

#define BLINK_TIM_0_066							0x00
#define BLINK_TIM_0_25							0x01
#define BLINK_TIM_0_50							0x02
#define BLINK_TIM_0_75							0x03
#define BLINK_TIM_1_00							0x04
#define BLINK_TIM_1_25							0x05
#define BLINK_TIM_1_50							0x06
#define BLINK_TIM_2_00							0x07

#define AUTO_MOVING_OFF							0x00
#define AUTO_MOVING_ON							0x01

#define FONT_01									0x02
#define FONT_02									0x03


//User define Char


#define PATTERN_SIZE							0x08

//#define CH_ARROW	{0x00, 0x04, 0x0E, 0x15, 0x04, 0x04, 0x04,0x00}




#endif /* SRC_LCD_DRIVER_LCDCONFIG_H_ */
