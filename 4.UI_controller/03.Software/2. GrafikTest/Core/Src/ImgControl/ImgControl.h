/*
 * ImgControl.h
 *
 *  Created on: 07.07.2020
 *      Author: marcel
 */

#ifndef SRC_IMGCONTROL_IMGCONTROL_H_
#define SRC_IMGCONTROL_IMGCONTROL_H_

#include "stm32f3xx_hal.h"
#include "math.h"
#include <bitset>
#include "../LCD_Driver/LCDDriver.h"



class ImgControl {

public:
	//general init functions
	ImgControl(LCDDriver *lcdDriver);
	void initImgControl(void);


	//rectangle functions
	void writeXLine(uint8_t startX, uint8_t startY, uint8_t width, uint8_t lineThickness);
	void writeYLine(uint8_t startX, uint8_t startY, uint8_t height, uint8_t lineThickness);
	void writeRectangle(uint8_t startX, uint8_t startY, uint8_t width,uint8_t height, uint8_t lineThickness);

	//circle functions
	void writeCircle(uint8_t center_x, uint8_t center_y, uint8_t radius);

	//write functions
	void clearMirror(void);
	void writeScreenMirror(void);


private:

	//instancen
	LCDDriver *lcdDriver;

	//bitsets
	bitset<LCD_WIDTH_PX> screenMirror[LCD_HEIGHT_PX];
	bitset<LCD_WIDTH_PX> screenMirrorLast[LCD_HEIGHT_PX];


};



#endif /* SRC_IMGCONTROL_IMGCONTROL_H_ */
