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
  EspMQTTSketch(String mqttServer, char mqttPort, String mqttClientName, String wifiSSID, String wifiPassword, String devicePath);
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
  String devicePath;
  WiFiClient espClient;
  PubSubClient* client;
};

#endif
