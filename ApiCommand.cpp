#include "ApiCommand.h"

ApiCommand::ApiCommand() {
}

ApiCommand::~ApiCommand() {
}

void ApiCommand::initGSM()
{
  bool started=false;
  Serial.println("GSM Shield testing.");
  //Start configuration of shield with baudrate.
  //For http uses is raccomanded to use 4800 or slower.
  if (gsm.begin(9600)) {
    Serial.println("GSM READY");
    started=true;
  } else
    Serial.println("GSM IDLE");

  if(started) {
   //GPRS attach, put in order APN, username and password.
   //If no needed auth let them blank.
   if (inet.attachGPRS(APN_NAME, "", ""))
    Serial.println("GPRS ATTACHED");
   else
    Serial.println("GPRS ERROR");

   delay(1000);
   }
}


void ApiCommand::powerUpGSM(bool powerOff)
{
  pinMode(44, OUTPUT);
  digitalWrite(44, LOW);
  delay(1000);
  digitalWrite(44, HIGH);
  delay(2000);
  digitalWrite(44, LOW);
  Serial.println("POWered");
  if (!powerOff)
    delay(13000);
}
