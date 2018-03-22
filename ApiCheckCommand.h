/*
 * ApiCheckCommand.h
 *
 *  Created on: 21 Mar 2018
 *      Author: chverma
 */

#ifndef APICHECKCOMMAND_H_
#define APICHECKCOMMAND_H_

#include "Command.h"
#include "Arduino.h"
#include <Servo.h> 
#include "inetGSM.h"

class ApiCheckCommand: public Command {
public:
	ApiCheckCommand();
	virtual ~ApiCheckCommand();
	void execute(String parameter);
  char msg[500];
};

#endif /* APICHECKCOMMAND_H_ */
