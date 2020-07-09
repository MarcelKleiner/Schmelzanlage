/*
 * ImgControl.cpp
 *
 *  Created on: 07.07.2020
 *      Author: marcel
 */

#include "ImgControl.h"
using namespace std;




ImgControl::ImgControl(LCDDriver *lcdDriver) {
	this->lcdDriver = lcdDriver;
}


void ImgControl::initImgControl(void){
	this->lcdDriver->InitLCD();
}




void ImgControl::writeScreenMirror(){
	//lcdDriver->writeScreen(screenMirror);
	for(uint8_t copy = 0; copy < LCD_HEIGHT; copy++){
		screenMirrorLast[copy] = (screenMirrorLast[copy] ^ screenMirror[copy]);
	}

	lcdDriver->WriteData_16bit(LCD_setAddressPointer, LCD_GRAPHIC_START_ADDR);				//set Address pointer to Graphic home Address
	uint8_t sendByte = 0;
	uint16_t addr = LCD_GRAPHIC_START_ADDR;


	for(uint8_t rowCounter = 0;rowCounter < LCD_HEIGHT; rowCounter++){

		if(screenMirrorLast[rowCounter].any()){




			lcdDriver->WriteData_16bit(LCD_setAddressPointer, addr);				//set Address pointer to Graphic home Address
			for(uint8_t columnCounter = 0; columnCounter < 40; columnCounter++){
				sendByte = 0;
				for(uint8_t bitCounter = 0; bitCounter<6; bitCounter++){
					sendByte |= screenMirror[rowCounter][0];
					sendByte<<=1;
					screenMirror[rowCounter]>>=1;
				}
				sendByte>>=1;

				lcdDriver->WriteData_8bit(LCD_dataWriteAndIncrementADP,sendByte);
			}



			addr = addr + 40;

		}else{
			addr = addr + 40;
		}

	}

	for(uint8_t copy = 0; copy < LCD_HEIGHT; copy++){
		screenMirrorLast[copy] = screenMirror[copy];
		screenMirror[copy].reset();
	}
}


void ImgControl::writeXLine(uint8_t startX, uint8_t startY, uint8_t width, uint8_t lineThickness){
	for(uint8_t i = 0; i<width; i++){
		screenMirror[startY][startX+i] = 1;
	}

}


void ImgControl::writeYLine(uint8_t startX, uint8_t startY, uint8_t height, uint8_t lineThickness){
	for(uint8_t i = 0; i<height; i++){
		screenMirror[startY+i][startX] = 1;
	}
}


void ImgControl::writeRectangle(uint8_t startX, uint8_t startY, uint8_t width,uint8_t height, uint8_t lineThickness){
	writeXLine(startX, startY, width, lineThickness);
	writeYLine(startX, startY, height, lineThickness);
	writeXLine(startX, startY+height, width, lineThickness);
	writeYLine(startX+width, startY, height, lineThickness);

}


void ImgControl::clearMirror(){
	for(uint8_t i = 0; i<LCD_HEIGHT;i++){
		screenMirror[i].reset();
	}
}


