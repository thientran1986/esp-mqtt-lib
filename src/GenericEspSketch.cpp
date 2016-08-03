#include "GenericEspSketch.h"

extern GenericEspSketch esp;

GenericEspSketch::GenericEspSketch(String mqttServer, char mqttPort, String mqttClientName, String wifiSSID, String wifiPassword, String devicePath){
  this->mqttServer = mqttServer;
  this->mqttPort = mqttPort;
  this->mqttClientName = mqttClientName;
  this->wifiSSID = wifiSSID;
  this->wifiPassword = wifiPassword;
  this->client = new PubSubClient(this->espClient);
}

GenericEspSketch::~GenericEspSketch(){
  delete this->client;
}

void GenericEspSketch::setDebug(bool debug){
  this->debug = debug;
}

bool GenericEspSketch::isDebug(){
  return this->debug;
}

void GenericEspSketch::setup(){
  Serial.begin(115200);
  this->initializeWifi();
  this->initializeEspPubSubClient();
}

void GenericEspSketch::loop(){
  // put your main code here, to run repeatedly:
  if (!this->client->connected()) {
    this->reconnect();
  }
  this->client->loop();
  delay(500);
}

void GenericEspSketch::reconnect(){
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

void GenericEspSketch::onMessage(){

}

void GenericEspSketch::initializeWifi(){
  delay(10);
  // We start by connecting to a WiFi network
  Serial.print("Connecting to ");
  Serial.println(this->wifiSSID);

  WiFi.begin(this->wifiSSID.c_str(), this->wifiPassword.c_str());

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void GenericEspSketch::initializeEspPubSubClient(){
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
    Serial.println();
  }
}
