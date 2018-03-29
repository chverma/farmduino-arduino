/*
 * WaterOnCommand.h
 *
 *  Created on: 21 Mar 2018
 *      Author: chverma
 */

#include "WaterOnCommand.h"

WaterOnCommand::WaterOnCommand() {
  instruction = "waterOff";
}

WaterOnCommand::~WaterOnCommand() {
}

void WaterOnCommand::execute(String parameter){
  Servo waterServo;
  int pinNo = parameter.toInt();
  waterServo.attach(pinNo);
  //Serial connection.
  waterServo.write(0);  // set servo to mid-point
  Serial.println(" water on");
  delay(1000);
  waterServo.detach();
}
