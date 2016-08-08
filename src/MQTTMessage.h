#ifndef __MQTT_MESSAGE__
#define __MQTT_MESSAGE__

#ifndef _MQTT_ACTION_
#define _MQTT_ACTION_
    enum MQTTAction{
    GET,
    SET,
    PING,
    REGISTER
  };
#endif

class MQTTMessage {
public:
  MQTTMessage();
  ~MQTTMessage();
protected:
  long timeStamp;
  MQTTAction action;
  char* source;
  char* data;
};

#endif
