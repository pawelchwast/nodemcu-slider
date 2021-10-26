#pragma once

#include <Arduino.h>
#include <SPI.h>
#include "SH1106.h"
#include "SH1106Ui.h"
#include "BatteryMonitor.h"
#include "Overlay.h"
#include "Frames.h"

class Oled_ {
  private:
    Oled_() = default; // Make constructor private

  public:
    static Oled_ &getInstance(); // Accessor for singleton instance
    
    static bool msOverlay(SH1106 *display, SH1106UiState* state) {
      display->setTextAlignment(TEXT_ALIGN_RIGHT);
      display->setFont(ArialMT_Plain_10);
      display->drawString(128, 0, String(BatteryMonitor.getBusVoltage()) + "V");
      return true;
    }

    Oled_(const Oled_ &) = delete; // no copying
    Oled_ &operator=(const Oled_ &) = delete;

  public:
    void begin();
    int update();
    void setOverlay();
    
};

extern Oled_ &Oled;