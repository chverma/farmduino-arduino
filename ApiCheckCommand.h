/*
 * ApiCheckCommand.h
 *
 *  Created on: 21 Mar 2018
 *      Author: chverma
 */

#ifndef APICHECKCOMMAND_H_
#define APICHECKCOMMAND_H_

#include "ApiCommand.h"
#include "Arduino.h"
#include <Servo.h>
#include "Command.h"


class ApiCheckCommand: public ApiCommand {
public:
  ApiCheckCommand(int *ok);
  virtual ~ApiCheckCommand();
  void execute(String parameter);
};

#endif /* APICHECKCOMMAND_H_ */
