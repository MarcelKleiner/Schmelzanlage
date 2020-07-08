/*
 * AppMain.h
 *
 *  Created on: May 31, 2020
 *      Author: marcel
 */

#include "stm32f3xx_hal.h"
#include "main.h"


#include"../ImgControl/ImgControl.h"
#include "../LCD_Driver/LCDDriver.h"


#ifndef SRC_APPMAIN_APPMAIN_H_
#define SRC_APPMAIN_APPMAIN_H_

class AppMain {
public:
	AppMain();

	void main(void);
private:

	LCDDriver lcdDriver = LCDDriver();
	ImgControl imgControl = ImgControl(&lcdDriver);
};

#endif /* SRC_APPMAIN_APPMAIN_H_ */
