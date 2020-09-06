/*
 * Screensaver.cpp
 *
 *  Created on: 11.07.2020
 *      Author: Marcel-Laptop
 */

#include "Screensaver.h"



Screensaver::Screensaver(ImgControl *imgControl){
	this->imgControl = imgControl;
	posCounter_y = startPos_y;		//reset position counter
	posCounter_x = startPos_x;		//reset position counter
	shapeHeight = 10;	//set shape size to default
	shapeWidth = 30;	//set shape size to default
}


void Screensaver::resetScreensaver(void){
	posCounter_y = 0; 	//reset position counter
	currentState = s1;	//reset currentState
	nextState = s1;		//reset nextState
	imgControl->clearMirror();	//clear LCD graphic
}

void Screensaver::setShapeSize(uint8_t width, uint8_t height){
	shapeHeight = height;
	shapeWidth = width;
}

void Screensaver::setStartPos(uint8_t x, uint8_t y){
	startPos_x = y;
	startPos_y = x;
}


void Screensaver::screensaver(void){

	currentState = nextState;

	switch(currentState){
	case s1:
		posCounter_y = startPos_y;		//reset position counter
		posCounter_x = startPos_x;		//reset position counter
		nextState = s7;
		break;
	case s2:
		posCounter_x++;		//reset position counter
		posCounter_y--;		//reset position counter
		if(posCounter_x == LCD_WIDTH_PX-shapeWidth){
			nextState = s4;
		}
		if(posCounter_y == 0){
			nextState = s7;
		}
		break;
	case s3:
		posCounter_x--;		//reset position counter
		posCounter_y--;		//reset position counter
		if(posCounter_x == 0){
			nextState = s9;
		}
		if(posCounter_y == 0){
			nextState = s6;
		}
		break;
	case s4:
		posCounter_x--;		//reset position counter
		posCounter_y--;		//reset position counter
		if(posCounter_x == 0){
			nextState = s9;
		}
		if(posCounter_y == 0){
			nextState = s6;
		}
		break;
	case s5:
		posCounter_x--;		//reset position counter
		posCounter_y++;		//reset position counter
		if(posCounter_x == 0){
			nextState = s8;
		}
		if(posCounter_y == LCD_HEIGHT_PX-shapeHeight){
			nextState = s3;
		}
		break;
	case s6:
		posCounter_x--;		//reset position counter
		posCounter_y++;		//reset position counter
		if(posCounter_x == 0){
			nextState = s8;
		}
		if(posCounter_y == LCD_HEIGHT_PX-shapeHeight){
			nextState = s3;
		}

		break;
	case s7:
		posCounter_x++;		//reset position counter
		posCounter_y++;		//reset position counter
		if(posCounter_x == LCD_WIDTH_PX-shapeWidth){
			nextState = s5;
		}
		if(posCounter_y == LCD_HEIGHT_PX-shapeHeight){
			nextState = s2;
		}
		break;
	case s8:
		posCounter_x++;		//reset position counter
		posCounter_y++;		//reset position counter
		if(posCounter_x == LCD_WIDTH_PX-shapeWidth){
			nextState = s5;
		}
		if(posCounter_y == LCD_HEIGHT_PX-shapeHeight){
			nextState = s2;
		}
		break;
	case s9:
		posCounter_x++;		//reset position counter
		posCounter_y--;		//reset position counter
		if(posCounter_x == LCD_WIDTH_PX-shapeWidth){
			nextState = s4;
		}
		if(posCounter_y == 0){
			nextState = s7;
		}

		break;
	default:
		currentState = s1;
		break;
	}

	imgControl->writeRectangle(posCounter_x, posCounter_y, shapeWidth, shapeHeight, 1);
	//imgControl->writeScreenMirror();

}
