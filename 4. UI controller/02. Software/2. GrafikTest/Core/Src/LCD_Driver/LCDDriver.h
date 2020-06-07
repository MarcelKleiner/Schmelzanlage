/*
 * LCDDriver.h
 *
 *  Created on: May 31, 2020
 *      Author: marcel
 */

#ifndef SRC_LCD_DRIVER_LCDDRIVER_H_
#define SRC_LCD_DRIVER_LCDDRIVER_H_

#include "stm32f3xx_hal.h"


#define LCD_TIMEOUT		10

class LCDDriver {
public:
	LCDDriver();
	void InitLCD(void);

	typedef enum LCD_STATUS_{
		LCD_STATUS_OK,
		LCD_STATUS_ERROR
	}LCD_STATUS;

	bool WriteData_8bit(uint8_t addr, uint8_t data);
	bool WriteData_16bit(uint8_t addr, uint16_t data);
	bool WriteText(char* data);


private:





	uint8_t ReadDataPin(void);
	void WriteDataPin(uint8_t data);

	void Reset(void);
	LCD_STATUS CheckStatus(uint8_t timeOUt);






};

#endif /* SRC_LCD_DRIVER_LCDDRIVER_H_ */
