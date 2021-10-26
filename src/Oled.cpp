
#include "Oled.h"
#define OLED_RESET  D1   // RESET
#define OLED_DC     D2   // Data/Command
#define OLED_CS     D8   // Chip select

SH1106 display(true, OLED_RESET, OLED_DC, OLED_CS);
SH1106Ui ui     ( &display );

bool msOverlay(SH1106 *display, SH1106UiState* state) {
  display->setTextAlignment(TEXT_ALIGN_RIGHT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(128, 0, String(BatteryMonitor.getBusVoltage()) + "V");
  return true;
}

bool drawFrame2(SH1106 *display, SH1106UiState* state, int x, int y) {
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(0 + x, 10 + y, "Arial 10");

  display->setFont(ArialMT_Plain_16);
  display->drawString(0 + x, 20 + y, "Arial 16");

  display->setFont(ArialMT_Plain_24);
  display->drawString(0 + x, 34 + y, "Arial 24");

  return false;
}


bool drawFrame5(SH1106 *display, SH1106UiState* state, int x, int y) {
  // INA:
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);

  float busvoltage = 0;

  // Serial.print("Bus Voltage:   "); Serial.print(busvoltage); Serial.println(" V");
  // Serial.print("Shunt Voltage: "); Serial.print(shuntvoltage); Serial.println(" mV");
  // Serial.print("Load Voltage:  "); Serial.print(loadvoltage); Serial.println(" V");
  // Serial.print("Current:       "); Serial.print(current_mA); Serial.println(" mA");
  // Serial.print("Power:         "); Serial.print(power_mW); Serial.println(" mW");
  // Serial.println("");
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(0 + x, 10 + y, "Battery Voltage " + String(BatteryMonitor.getBusVoltage()) + "V");

  return false;
}

int frameCount = 2;
bool (*frames[])(SH1106 *display, SH1106UiState* state, int x, int y) = { drawFrame2, drawFrame5 };
bool (*overlays[])(SH1106 *display, SH1106UiState* state)             = { msOverlay };
int overlaysCount = 1;

void Oled_::begin() {
  
  ui.setTargetFPS(30);
  ui.setIndicatorPosition(BOTTOM);
  ui.setIndicatorDirection(LEFT_RIGHT);
  ui.setFrameAnimation(SLIDE_LEFT);
  ui.setFrames(frames, frameCount);
  ui.setOverlays(overlays, overlaysCount);
  ui.init();
  display.flipScreenVertically();
}

int Oled_::update() {
  return ui.update();
}

float Oled_::getBusVoltage() {
  return this->busVoltage;
}

Oled_ &Oled_::getInstance() {
  static Oled_ instance;
  return instance;
}

Oled_ &Oled = Oled.getInstance();