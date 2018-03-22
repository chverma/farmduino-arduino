#include "farmduino.h"


// create objects for each command
WaterOnCommand wOnCommand;
WaterOffCommand wOffCommand;
ApiCheckCommand apiCheckCommand;
TimedCommand *tCommands[30];

RTC_DS1307 rtc; // Date and time functions using a DS1307 RTC connected via I2C and Wire lib. To change pins for Software Serial, use the two lines in GSM.cpp.
Cron cron(tCommands, 0);
InetGSM inet;
char msg[500];
int numdata;
char inSerial[50];
int i=0;
boolean started=false;
TimedCommand command("*.*.20.*.*.*", &apiCheckCommand, SERVO_PIN, true);
TimedCommand command1("*.*.8.*.*.*", &wOnCommand, SERVO_PIN, true);
TimedCommand command2("20.*.*.*.*.*",&wOnCommand, SERVO_PIN);
TimedCommand command3("25.*.*.*.*.*",&wOffCommand, SERVO_PIN);
void setup()
{
     // initCron();
     Serial.begin(9600);
     if (! rtc.begin()) {
       Serial.println("Couldn't find RTC");
       while (1);
     }
     
     cron.addTimedCommand(&command);
     cron.addTimedCommand(&command2);
     cron.addTimedCommand(&command3);
     int *i = 0;
     //Serial.println(typeid(i).name());
        // sets the time to be the date and time of the compilation
        //cron.setTime(rtc.now());
        // prints the current time
        
        cron.printTime();
     if (! rtc.isrunning()) {
        Serial.println("RTC is NOT running!");
        // following line sets the RTC to the date & time this sketch was compiled
        //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
     }

//    powerUpGSM();
//    initGSM();
    
     
     
};


void loop()
{
    cron.loop();
    cron.printTime();
//    DateTime now = rtc.now();
//    
//    Serial.print(now.year(), DEC);
//    Serial.print('/');
//    Serial.print(now.month(), DEC);
//    Serial.print('/');
//    Serial.print(now.day(), DEC);
//    Serial.print(' ');
//    Serial.print(now.hour(), DEC);
//    Serial.print(':');
//    Serial.print(now.minute(), DEC);
//    Serial.print(':');
//    Serial.print(now.second(), DEC);
//    Serial.println();
    //delay(1000);
    //sleep(50);     
}


void sleep(int sec) {
  while (sec >= 8) {
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    sec -= 8;
  }
  if (sec >= 4) {
    LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
    sec -= 4;
  }
  if (sec >= 2) {
    LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);
    sec -= 2;
  }
  if (sec >= 1) {
    LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
    sec -= 1;
  }
  //sendSignal();
}
void initGSM()
{
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
   if (inet.attachGPRS("orangeworld", "", ""))
    Serial.println("GPRS ATTACHED");
   else 
    Serial.println("GPRS ERROR");
    
   delay(1000);
   }
}


void powerUpGSM()
{
  pinMode(44, OUTPUT);
  digitalWrite(44, LOW);
  delay(1000);
  digitalWrite(44, HIGH);
  delay(2000);
  digitalWrite(44, LOW);
  Serial.println("POWered");
  delay(3000);
  delay(10000);
}



void httpGetActionDone() {
          //TCP Client GET, send a GET request to the server and
          //save the reply.
          int len = 97;
          numdata=inet.httpGET(FARMDUINO_SERVER, 80, "/rest/v1/api/check", msg, 500);
          //Print the results.
          Serial.println("Number of data received:");
          Serial.println(numdata);
          Serial.println("Data received:");
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

void httpGetWaterAction() {
          //TCP Client GET, send a GET request to the server and
          //save the reply.
          numdata=inet.httpGET(FARMDUINO_SERVER, 80, API_CHECK, msg, 500);
          //Print the results.
          Serial.println("Number of data received:");
          Serial.println(numdata);
          Serial.println("Data received:");
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
