#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_INA219.h>

class BatteryMonitor_ {
  private:
    BatteryMonitor_() = default; // Make constructor private
    float busVoltage;

  public:
    static BatteryMonitor_ &getInstance(); // Accessor for singleton instance

    BatteryMonitor_(const BatteryMonitor_ &) = delete; // no copying
    BatteryMonitor_ &operator=(const BatteryMonitor_ &) = delete;

  public:
    void begin();
    void doStuff();
    float getBusVoltage();
};

extern BatteryMonitor_ &BatteryMonitor;