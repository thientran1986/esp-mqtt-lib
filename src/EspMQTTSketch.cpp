#include "EspMQTTSketch.h"

extern EspMQTTSketch esp;
extern char serialPort;

EspMQTTSketch::EspMQTTSketch(String mqttServer, char mqttPort, String mqttClientName, String wifiSSID, String wifiPassword, String mqttTopic){
  this->mqttServer = mqttServer;
  this->mqttPort = mqttPort;
  this->mqttClientName = mqttClientName;
  this->wifiSSID = wifiSSID;
  this->wifiPassword = wifiPassword;
  this->mqttTopic = mqttTopic;
  this->client = new PubSubClient(this->espClient);
}

EspMQTTSketch::~EspMQTTSketch(){
  delete this->client;
}

void EspMQTTSketch::setDebug(bool debug){
  this->debug = debug;
}

bool EspMQTTSketch::isDebug(){
  return this->debug;
}

void EspMQTTSketch::setup(){
  Serial.begin(serialPort);
  this->initializeWifi();
  this->initializeEspPubSubClient();
}

void EspMQTTSketch::loop(){
  // put your main code here, to run repeatedly:
  ArduinoOTA.handle();

  if (!this->client->connected()) {
    this->reconnect();
  }
  this->client->loop();
  delay(200);
}

void EspMQTTSketch::reconnect(){
  while (!this->client->connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    // If you do not want to use a username and password, change next line to
    // if (client.connect("ESP8266Client")) {
    if (this->client->connect(this->mqttClientName.c_str())) {
      Serial.println("Connected");
      this->client->setCallback(callback);
    } else {
      Serial.print("failed, rc=");
      Serial.print(this->client->state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void EspMQTTSketch::initializeWifi(){
  delay(10);
  // We start by connecting to a WiFi network
  Serial.print("Connecting to ");
  Serial.println(this->wifiSSID);

  WiFi.mode(WIFI_STA);
  WiFi.begin(this->wifiSSID.c_str(), this->wifiPassword.c_str());

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

  ArduinoOTA.onStart([]() {
   String type;
   if (ArduinoOTA.getCommand() == U_FLASH)
     type = "sketch";
   else // U_SPIFFS
     type = "filesystem";

   // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
   Serial.println("Start updating " + type);
 });
 ArduinoOTA.onEnd([]() {
   Serial.println("\nEnd");
 });
 ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
   Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
 });
 ArduinoOTA.onError([](ota_error_t error) {
   Serial.printf("Error[%u]: ", error);
   if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
   else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
   else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
   else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
   else if (error == OTA_END_ERROR) Serial.println("End Failed");
 });
 ArduinoOTA.begin();
 Serial.println("Ready");
 Serial.print("IP address: ");
 Serial.println(WiFi.localIP());
}

void EspMQTTSketch::initializeEspPubSubClient(){
  this->client->setServer(this->mqttServer.c_str(), this->mqttPort);
}

/*CALL BACK FUNC*/
void callback(char* topic, byte* payload, unsigned int length) {
  if(esp.isDebug()){
    Serial.println();
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    // Parsing Message
    Serial.println();
  }
  esp.onMessage();
}

void EspMQTTSketch::onMessage(){

}
