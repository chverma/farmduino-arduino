// NOTE: Copy this file to farmduino.h.
// Replace FARMDUINO_SERVER by your API URL
#ifndef FARMDUINO_H_
#define FARMDUINO_H_

#define API_CHECK "/rest/v1/api/check"
#define API_GET_WATER "/rest/v1/cron/get/water"
#define FARMDUINO_SERVER "url api server"
#define SERVO_PIN "34"


#include "SIM900.h"
#include <SoftwareSerial.h>
#include "inetGSM.h"
#include <Wire.h>
#include "RTClib.h"
#include "SwitchOnCommand.h"
#include "TimedCommand.h"
#include "Cron.h"
#include "WaterOffCommand.h"
#include "WaterOnCommand.h"
#include "ApiCheckCommand.h"
#include "ApiWaterCommand.h"
#include "LowPower.h"
#include <ArduinoJson.h>

#endif /* FARMDUINO_H_ */
