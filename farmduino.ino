#include "farmduino.h"

// Date and time functions using a DS1307 RTC connected via I2C and Wire lib. To change pins for Software Serial, use the two lines in GSM.cpp.
RTC_DS1307 rtc;

// create objects for each command
WaterOnCommand wOnCommand;
WaterOffCommand wOffCommand;
// Define output variable for ApiCheckCommand
int apiChecked=0;
ApiCheckCommand apiCheckCommand(&apiChecked);

// Define output variables for ApiWaterCommand
String cronStrWaterOn = "-2.*.*.*.*.*";
String cronStrWaterOff = "-2.*.*.*.*.*";
int cronLinesUpdated = 0;
ApiWaterCommand apiGetWaterCommand(&cronLinesUpdated, &cronStrWaterOn, &cronStrWaterOff);

// Define a TimedCommand array with a static size
TimedCommand *tCommands[4];
// Define the cron object
Cron cron(tCommands, 0);

// Declare commands to be modified by later by commApiGetWater.
// NOTE: The value -2 has been set to not match the current time. So, it won't be executed until the cron strings has been modified.
TimedCommand commApiCheck("-2.*.[7,8,9,10,11,12,13,14,15,14,17,19,23,3].*.*.*", &apiCheckCommand, SERVO_PIN, true, 2);
TimedCommand commApiGetWater("*.*.[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23].*.*.*", &apiGetWaterCommand, SERVO_PIN, true, 2);
TimedCommand commWaterOn("-2.*.*.*.*.*", &wOnCommand, SERVO_PIN, true, 2);
TimedCommand commWaterOff("-2.*.*.*.*.*",&wOffCommand, SERVO_PIN, true, 2);

void setup()
{
  Serial.begin(9600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
  }
  cron.printTime();
  // Add cron API commands
  cron.addTimedCommand(&commApiCheck);
  cron.addTimedCommand(&commApiGetWater);
  // Add cron WATER ON/OFF commands
  cron.addTimedCommand(&commWaterOn);
  cron.addTimedCommand(&commWaterOff);
  cron.printTime();
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  delay(1000);
};

int waitForSleep = 0;
void loop()
{
  cron.loop();
  cron.printTime();
    
  if (cronLinesUpdated) {
    Serial.println("Cron lines updated!");
    updateCronStrings();
    cronLinesUpdated = 0;
    waitForSleep = 20;
   }
   
   if (waitForSleep == 0){
      //sleep(30*60);
      waitForSleep++;
    } else {
      waitForSleep--;
    }
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
}

void updateCronStrings(){
  Serial.println("cronStrWaterOn: "+cronStrWaterOn);
  Serial.println("cronStrWaterOff: "+cronStrWaterOff);
  commWaterOn.setCronString(cronStrWaterOn);
  commWaterOff.setCronString(cronStrWaterOff);
}

