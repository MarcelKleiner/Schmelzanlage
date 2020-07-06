/*
 * LCDDriver.h
 *
 *  Created on: May 31, 2020
 *      Author: marcel
 */

#ifndef SRC_LCD_DRIVER_LCDDRIVER_H_
#define SRC_LCD_DRIVER_LCDDRIVER_H_

#include "stm32f3xx_hal.h"
#include<string> // for string class
#include "LCDConfig.h"


using namespace std;


#define LCD_TIMEOUT			50
#define LCD_WIDTH			240
#define LCD_HEIGHT			128

#define LCD_TXT_START_ADDR		0x0000
#define LCD_GRAPHIC_START_ADDR	0x0400


class LCDDriver {
public:
	LCDDriver();
	void InitLCD(void);


	void SetAddressPointer(uint8_t column, uint8_t row);
	bool WriteText(string data);
	void WritePixel(uint8_t x, uint8_t y, bool pixelOnOff);
	void WriteRectangle(uint8_t startX, uint8_t startY, uint8_t width, uint8_t height, uint8_t lineThickness);
	void WriteXLine(uint8_t startX,uint8_t startY, uint8_t width, uint8_t lineThickness);
	void WriteYLine(uint8_t startX,uint8_t startY, uint8_t height, uint8_t lineThickness);

	void ClearDisplay(void);


private:

	typedef enum LCD_STATUS_{
		LCD_STATUS_OK,
		LCD_STATUS_ERROR
	}LCD_STATUS;

	typedef enum PIN_DIRECTION_{
		PIN_OUTPUT,
		PIN_INPUT
	}PIN_DIRECTION;

	typedef enum LCD_SIZE_{
		SIZE_40C,
		SIZE_32C
	}LCD_SIZE;

	struct LCD_XY_SIZE_{
		uint8_t column;
		uint8_t row;
		uint8_t patternHeight;
		uint8_t patternWidth;
	}LCD_XY_SIZE;


	void SetLCDSize(LCD_SIZE size);
	void GPIO_Direction(PIN_DIRECTION pinDirection);


	void setUserChar(uint8_t CHAR[], uint16_t offsetReg, uint16_t addr);

	void Reset(void);
	void PushData(void);


	bool WriteData_8bit(uint8_t addr);
	bool WriteData_8bit(uint8_t addr, uint8_t data);
	bool WriteData_16bit(uint8_t addr, uint16_t data);

	LCD_STATUS CheckStatus(uint8_t timeOUt);

	uint8_t ReadDataPin(void);
	void WriteDataPin(uint8_t data);


};

#endif /* SRC_LCD_DRIVER_LCDDRIVER_H_ */
