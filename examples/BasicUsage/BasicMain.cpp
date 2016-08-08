#include <EspMQTTSketch.h>

#define MQTT_SERVER "192.168.0.222"
#define MQTT_PORT 1883
#define MQTT_DEVICE_TOPIC "/a/b"
#define WIFI_SSID "ClearOneWifi_F2"
#define WIFI_PASS "ClearOne"


char serialPort = 9600;
EspMQTTSketch esp(MQTT_SERVER, MQTT_PORT, "ESPClient", WIFI_SSID, WIFI_PASS, MQTT_DEVICE_TOPIC);

void setup() {
  esp.setDebug(true);
  esp.setup();
}

void loop() {
  delay(1000);
  Serial.println("Hello World!");
  esp.loop();
}
