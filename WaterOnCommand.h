/*
 * WaterOnCommand.h
 *
 *  Created on: 21 Mar 2018
 *      Author: chverma
 */

#ifndef WATERONCOMMAND_H_
#define WATERONCOMMAND_H_

#include "Command.h"
#include "Arduino.h"
#include <Servo.h>

class WaterOnCommand: public Command {
public:
  WaterOnCommand();
  virtual ~WaterOnCommand();
  void execute(String parameter);
private:
  Servo waterServo;
};

#endif /* WATERONCOMMAND_H_ */
