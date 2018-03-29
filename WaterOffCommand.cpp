/*
 * WaterOffCommand.h
 *
 *  Created on: 21 Mar 2018
 *      Author: chverma
 */

#include "WaterOffCommand.h"

WaterOffCommand::WaterOffCommand() {
	instruction = "waterOff";

}

WaterOffCommand::~WaterOffCommand() {
}

void WaterOffCommand::execute(String parameter){
  Servo waterServo;
  int pinNo = parameter.toInt();
  waterServo.attach(pinNo);
  //Serial connection.
  waterServo.write(90);  // set servo to mid-point
  Serial.println(" water off");
  delay(1000);
  waterServo.detach();
}
