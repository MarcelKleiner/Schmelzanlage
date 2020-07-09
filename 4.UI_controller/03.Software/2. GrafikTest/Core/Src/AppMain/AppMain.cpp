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
	uint8_t i = 0;
	uint8_t u = 0;
	while(1){

		//unten rechts
		while(i < 113 && u<210){
			imgControl.writeRectangle(u, i, 30, 15, 1);
			imgControl.writeScreenMirror();
			i++;
			u++;
		}

		if(i == 113){
			i--;
			//----hat unten angeschlagen----
			//nach oben rechts (anschlag unten)
			while(i > 0 && u<210){
				imgControl.writeRectangle(u, i, 30, 15, 1);
				imgControl.writeScreenMirror();
				i--;
				u++;
			}
			if(u==210){
				//nach oben links (anschlag rechts
				while(i > 0 && u>0){
					imgControl.writeRectangle(u, i, 30, 15, 1);
					imgControl.writeScreenMirror();
					i--;
					u--;
				}
				if(i == 0){
								//hat oben angeschlagen
								//nach unten rechts
								while(i < 113 && u>0){
									imgControl.writeRectangle(u, i, 30, 15, 1);
									imgControl.writeScreenMirror();
									i++;
									u--;
								}
							}else{
								//hat links angeschlagen
							}
			}else{

			}

		}else{
			//---hat rechts angeschlagen----
			u--;
			//noch oben links
			while(i < 113 && u<210){
				imgControl.writeRectangle(u, i, 30, 15, 1);
				imgControl.writeScreenMirror();
				i--;
				u--;
			}

			if(i == 0){
				//hat oben angeschlagen
				//nach unten rechts
				while(i < 113 && u>0){
					imgControl.writeRectangle(u, i, 30, 15, 1);
					imgControl.writeScreenMirror();
					i++;
					u--;
				}
			}else{
				//hat links angeschlagen
			}

		}



	}



//	lcdDriver.WriteRectangle(122, 119, 29, 20, 1);
//	lcdDriver.WriteRectangle(123, 120, 28, 20, 1);
//	lcdDriver.WriteRectangle(124, 121, 27, 20, 1);
//	lcdDriver.WriteRectangle(125, 122, 26, 20, 1);
//	lcdDriver.WriteRectangle(126, 123, 25, 20, 1);
//	lcdDriver.WriteRectangle(127, 124, 24, 20, 1);
//	lcdDriver.WriteRectangle(128, 125, 23, 20, 1);
//	lcdDriver.WriteRectangle(129, 126, 22, 20, 1);
//	lcdDriver.WriteRectangle(130, 127, 21, 20, 1);
	while(1){

	}


}
