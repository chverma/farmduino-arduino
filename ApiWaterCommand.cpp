/*
 * ApiWaterCommand.cpp
 *
 *  Created on: 23 Mar 2018
 *      Author: chverma
 */

#include "ApiWaterCommand.h"

ApiWaterCommand::ApiWaterCommand(int *apiGetWaterP, String *cronOn, String *cronOff) {
	instruction = "ApiWaterCommand";
  cronStringOff = cronOff;
  cronStringOn = cronOn;
  apiGetWater = apiGetWaterP;
}

ApiWaterCommand::~ApiWaterCommand() {
}

void ApiWaterCommand::execute(String parameter){
  Serial.println("\nApiWaterCommand:");

  powerUpGSM(false);
  initGSM();
  //TCP Client GET, send a GET request to the server and
  //save the reply.
  int numdata=inet.httpGET(FARMDUINO_SERVER , 80, API_GET_WATER, msg, 500);
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
  String tOn = root[String("cronStringOn")];
  *cronStringOn = tOn;
  Serial.println(tOn);
  String tOff = root[String("cronStringOff")];
  *cronStringOff = tOff;
  Serial.println(tOff);
  *apiGetWater = 1;
  powerUpGSM(true);
  
}
