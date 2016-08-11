#ifndef __ESP_MQTT_LIB_CONSTANTS__
#define __ESP_MQTT_LIB_CONSTANTS__
  // Item type
  const char ITEM_TYPE_SWITCH=0;
  const char ITEM_TYPE_PIR=1;
  const char ITEM_TYPE_RFID=2;


  // Item actions
  const char SWITCH_OFF=0;
  const char SWITCH_ON=1;
  const char PIR_SENSOR_NONE=0;
  const char PIR_SENSOR_DETECTED=1;


  // MQTT Message action Constants
  const char MQTT_ACTION_GET=0;
  const char MQTT_ACTION_SET=1;
  const char MQTT_ACTION_PING=2;
  const char MQTT_ACTION_REGSITER=3;
  const char MQTT_ACTION_LOAD_FIRMWARE=4;
  const char MQTT_ACTION_RESET=5;
#endif
