#ifndef __SMART_ITEM__
  #define __SMART_ITEM__
  #include <Arduino.h>
  class SmartItem {
  public:
    SmartItem(char itemType);
    // ~SmartItem();
  protected:
    char itemType;
  };
#endif
