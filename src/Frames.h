#ifndef FRAMES_H
#define FRAMES_H
#include <Arduino.h>
#include "SH1106.h"
#include "SH1106Ui.h"
#include "BatteryMonitor.h"

class Frames {
  
  public:
    static bool arialFrame(SH1106 *display, SH1106UiState* state, int x, int y) {
        display->setTextAlignment(TEXT_ALIGN_LEFT);
        display->setFont(ArialMT_Plain_10);
        display->drawString(0 + x, 10 + y, "Arial 10");

        display->setFont(ArialMT_Plain_16);
        display->drawString(0 + x, 20 + y, "Arial 16");

        display->setFont(ArialMT_Plain_24);
        display->drawString(0 + x, 34 + y, "Arial 24");

        return false;
        }

    static bool powerFrame(SH1106 *display, SH1106UiState* state, int x, int y) {
        display->setTextAlignment(TEXT_ALIGN_LEFT);
        display->setFont(ArialMT_Plain_10);

        display->drawString(0 + x, 10 + y, "Voltage " + String(BatteryMonitor.getBusVoltage()) + "V");
        display->drawString(0 + x, 20 + y, "Power " + String(BatteryMonitor.getPower()) + "mW");
        return false;
    }

    int frameCount = 2;
    

    Frames();
};
#endif