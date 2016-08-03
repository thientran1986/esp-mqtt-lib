#include "GenericEspSketch.h"


GenericEspSketch::GenericEspSketch(char*wifiSSID, char*wifiPassword, char*devicePath){
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

bool GenericEspSketch::getDebug(){
  return this->debug;
}

void GenericEspSketch::setup(){

}

void GenericEspSketch::loop(){

}

void GenericEspSketch::onMessage(){

}

void GenericEspSketch::initializeWifi(){

}

void GenericEspSketch::initializeEspPubSubClient(){

}
