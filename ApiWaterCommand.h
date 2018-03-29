/*
 * ApiWaterCommand.h
 *
 *  Created on: 21 Mar 2018
 *      Author: chverma
 */
#ifndef APIWATERCOMMAND_H_
#define APIWATERCOMMAND_H_

//#include "ApiCommand.h"
#include "Arduino.h"
#include "farmduino.h"

class ApiWaterCommand: public ApiCommand {
public:
	ApiWaterCommand(int *, String *, String *);
	virtual ~ApiWaterCommand();
	void execute(String parameter);
private:
  char msg[500];
  String *cronStringOn;
  String *cronStringOff;
  int *apiGetWater;
};

#endif /* APIWATERCOMMAND_H_ */
