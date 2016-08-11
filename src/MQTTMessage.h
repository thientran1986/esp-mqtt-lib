#ifndef __MQTT_MESSAGE__
#define __MQTT_MESSAGE__

#include <Arduino.h>
#include "Constants.h"

class MQTTMessage {
public:
  MQTTMessage(char action);
  // ~MQTTMessage();
protected:
  char action;
};

#endif
