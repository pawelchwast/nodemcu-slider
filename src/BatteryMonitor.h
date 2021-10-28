#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_INA219.h>

class BatteryMonitor_ {
  private:
    BatteryMonitor_() = default; // Make constructor private
    float busVoltage;
    float power;
    float current;

  public:
    static BatteryMonitor_ &getInstance(); // Accessor for singleton instance

    BatteryMonitor_(const BatteryMonitor_ &) = delete; // no copying
    BatteryMonitor_ &operator=(const BatteryMonitor_ &) = delete;

  public:
    void begin();
    void update();
    float getBusVoltage();
    float getPower();
    float getCurrent();
};

extern BatteryMonitor_ &BatteryMonitor;