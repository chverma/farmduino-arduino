// NOTE: Copy this file to farmudino.h and replace CONSTANTS to your endpoint
// server setup
#ifndef FARMDUINO_H_
#define FARMDUINO_H_

#define API_CHECK "path to check api"
#define API_GET_WATER "path to get water cron"
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
