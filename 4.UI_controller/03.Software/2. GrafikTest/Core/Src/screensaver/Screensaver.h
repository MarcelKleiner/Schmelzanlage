/*
 * Screensaver.h
 *
 *  Created on: 11.07.2020
 *      Author: Marcel-Laptop
 */

#ifndef SRC_SCREENSAVER_SCREENSAVER_H_
#define SRC_SCREENSAVER_SCREENSAVER_H_

#include "../ImgControl/ImgControl.h"




class Screensaver {
public:
	Screensaver(ImgControl *imgControl);
	void resetScreensaver(void);
	void screensaver(void);
	void setShapeSize(uint8_t width, uint8_t height);
	void setStartPos(uint8_t x, uint8_t y);
private:
	ImgControl *imgControl;

	enum _state{
		s1,		s2,
		s3,		s4,
		s5,		s6,
		s7,		s8,
		s9
	};

	_state currentState;
	_state nextState;

	uint8_t shapeWidth;
	uint8_t shapeHeight;

	uint8_t posCounter_x;
	uint8_t posCounter_y;

	uint8_t startPos_x;
	uint8_t startPos_y;


};

#endif /* SRC_SCREENSAVER_SCREENSAVER_H_ */
