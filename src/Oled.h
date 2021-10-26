#pragma once

#include <Arduino.h>
#include <SPI.h>
#include "SH1106.h"
#include "SH1106Ui.h"
#include "BatteryMonitor.h"

class Oled_ {
  private:
    Oled_() = default; // Make constructor private
    float busVoltage;

  public:
    static Oled_ &getInstance(); // Accessor for singleton instance

    Oled_(const Oled_ &) = delete; // no copying
    Oled_ &operator=(const Oled_ &) = delete;

  public:
    void begin();
    int update();
    float getBusVoltage();
};

extern Oled_ &Oled;