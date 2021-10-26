#ifndef OVERLAY_H
#define OVERLAY_H
#include <Arduino.h>
#include <BatteryMonitor.h>
#include "SH1106.h"
#include "SH1106Ui.h"

class Overlay {
  
  public:
    static bool msOverlay(SH1106 *display, SH1106UiState* state) {
      display->setTextAlignment(TEXT_ALIGN_RIGHT);
      display->setFont(ArialMT_Plain_10);
      display->drawString(128, 0, String(BatteryMonitor.getBusVoltage()) + "V");
      return true;
    }

    int overlaysCount = 1;

    Overlay();
};
#endif