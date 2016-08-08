/**
* This API is used to build firmware for ESP-12 interact with MQTT.
*   1. ESP as its communication channel which is mqttTopic.
*   2. Communication with other device will be based on this topic.
*   3. MQTTMessage will contain data of the conversation
*/

#ifndef __GENERIC_ESP_SKETCH__
#define  __GENERIC_ESP_SKETCH__

#include <Arduino.h>
#include <PubSubClient.h>
#include <ESP8266WiFi.h>

#ifndef __PUB_SUB_CALLBACK__
  #define __PUB_SUB_CALLBACK__
  void callback(char* topic, byte* payload, unsigned int length);
#endif


class EspMQTTSketch{
public:
  EspMQTTSketch(String mqttServer, char mqttPort, String mqttClientName, String wifiSSID, String wifiPassword, String mqttTopic);
  ~EspMQTTSketch();
  virtual void setup();
  virtual void loop();
  void onMessage();
  void initializeWifi();
  void initializeEspPubSubClient();
  void setDebug(bool debug);
  bool isDebug();
protected:
  void reconnect();
  bool debug;
  String mqttServer;
  char mqttPort;
  String mqttClientName;
  String wifiSSID;
  String wifiPassword;
  String mqttTopic;
  WiFiClient espClient;
  PubSubClient* client;
};

#endif
