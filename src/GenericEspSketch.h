#ifndef __GENERIC_ESP_SKETCH__
#define  __GENERIC_ESP_SKETCH__

#include <Arduino.h>
#include <PubSubClient.h>
#include <ESP8266WiFi.h>

class GenericEspSketch{
public:
  GenericEspSketch(char*wifiSSID, char*wifiPassword, char*devicePath);
  ~GenericEspSketch();
  virtual void setup();
  virtual void loop();
  void onMessage();
  void initializeWifi();
  void initializeEspPubSubClient();
  void setDebug(bool debug);
  bool getDebug();
protected:
  bool debug;
  char* wifiSSID;
  char* wifiPassword;
  char* devicePath;
  WiFiClient espClient;
  PubSubClient* client;
};

#endif
