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
	ImgControl(LCDDriver *lcdDriver);
	void initImgControl(void);


	void writeXLine(uint8_t startX, uint8_t startY, uint8_t width, uint8_t lineThickness);
	void writeYLine(uint8_t startX, uint8_t startY, uint8_t height, uint8_t lineThickness);
	void writeRectangle(uint8_t startX, uint8_t startY, uint8_t width,uint8_t height, uint8_t lineThickness);


	void clearMirror(void);
	void writeScreenMirror(void);
private:





	LCDDriver *lcdDriver;
	bitset<240> screenMirror[128];
	bitset<240> screenMirrorLast[128];


};



#endif /* SRC_IMGCONTROL_IMGCONTROL_H_ */
