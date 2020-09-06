/*
 * AppMain.cpp
 *
 *  Created on: May 31, 2020
 *      Author: marcel
 */

#include "AppMain.h"

//#include<iostream>
#include<string> // for string class
using namespace std;

AppMain::AppMain() {
	// TODO Auto-generated constructor stub

}

void AppMain::main(){

	imgControl.initImgControl();
	screenSaver.setShapeSize(15,8);
	//screenSaver_1.setShapeSize(5, 10);

	screenSaver.setStartPos(0, 0);
	//screenSaver_1.setStartPos(20, 80);

//	lcdDriver.InitLCD();

	/*lcdDriver.SetAddressPointer(0, 0);
	lcdDriver.WriteText("Copyright (C) 1991-2020, B&K System AG");
	lcdDriver.SetAddressPointer(0, 2);
	lcdDriver.WriteText("Init System...");
	//HAL_Delay(1000);
	lcdDriver.SetAddressPointer(0, 3);
	lcdDriver.WriteText("Booting from internal ROM...");
	//HAL_Delay(800);
	lcdDriver.SetAddressPointer(0, 5);
	lcdDriver.WriteText("Main Processor : STM32F303K8");
	lcdDriver.SetAddressPointer(0, 6);
	lcdDriver.WriteText("Memory Testing : 64K OK ");
	//HAL_Delay(800);
	lcdDriver.SetAddressPointer(0, 15);
	lcdDriver.WriteText("Press F1 to enter BIOS...");

	lcdDriver.WriteRectangle(140, 50, 51, 30, 1);
	*/

	while(1){

		screenSaver.screensaver();
	//	screenSaver_1.screensaver();
		imgControl.writeScreenMirror();
	}


}
