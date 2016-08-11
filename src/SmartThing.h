#ifndef __SMART_THING__
  #define  __SMART_THING__
  #include <Arduino.h>
  #include "SmartItem.h"

  class SmartThing {
  public:
    SmartThing(char numberOfItem, const SmartItem *items);
    // ~SmartThing();
    void setIpAddress(String ipAddress){
      this->ipAddress = ipAddress;
    }
    String getIpAddress(){
      return this->ipAddress;
    }
  protected:
    String name;
    String uid;
    String ipAddress;
    String devicePath;
    char numberOfItem;
    const SmartItem* items;
  };
#endif
