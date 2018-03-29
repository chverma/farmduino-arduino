/*
 * ApiCommand.h
 *
 *  Created on: 21 Mar 2018
 *      Author: chverma
 */
#ifndef APICOMMAND_H_
#define APICOMMAND_H_

#include "Command.h"
#include "Arduino.h"
//#include "farmduino.h"
//#include "SIM900.h"
#include "inetGSM.h"
#define APN_NAME "orangeworld"

class ApiCommand : public Command {
public:
  ApiCommand();
  ~ApiCommand();
  void initGSM();
  void powerUpGSM(bool powerOff);
protected:
  char msg[500];
  InetGSM inet;
  int *ptr;
};

#endif /* APICOMMAND_H_ */
