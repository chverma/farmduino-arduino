/*
 * ApiCheckCommand.h
 *
 *  Created on: 21 Mar 2018
 *      Author: chverma
 */

#include "ApiCheckCommand.h"
#include "farmduino.h"
ApiCheckCommand::ApiCheckCommand() {
	instruction = "checkApi";

}

ApiCheckCommand::~ApiCheckCommand() {
}

void ApiCheckCommand::execute(String parameter){
  int pinNo = parameter.toInt();
  Serial.println("\nNumber of data received:");
  InetGSM inet;
  //TCP Client GET, send a GET request to the server and
  //save the reply.
  int numdata=inet.httpGET(FARMDUINO_SERVER , 80, API_CHECK, msg, 500);
  //Print the results.
  Serial.println("\nNumber of data received:");
  Serial.println(numdata);
  Serial.println("\nData received:");
  // Find where the json starts and ends
  int ind1 = String(msg).indexOf('{');
  int ind2 = String(msg).indexOf('}');
  // Get the substring
  String finalstring = String(msg).substring(ind1, ind2+1);
  // Create the json object
  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(finalstring);
  Serial.println(finalstring);
  Serial.println("AHI VA");
  String prova = root[String("from")];
  Serial.println(prova);
}
