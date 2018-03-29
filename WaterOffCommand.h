/*
 * WaterOffCommand.h
 *
 *  Created on: 21 Mar 2018
 *      Author: chverma
 */

#ifndef WATEROFFCOMMAND_H_
#define WATEROFFCOMMAND_H_

#include "Command.h"
#include "Arduino.h"
#include <Servo.h>

class WaterOffCommand: public Command {
public:
  WaterOffCommand();
  virtual ~WaterOffCommand();
  void execute(String parameter);
private:
  Servo waterServo;
};

#endif /* WATEROFFCOMMAND_H_ */
