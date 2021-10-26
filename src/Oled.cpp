
#include "Oled.h"
#define OLED_RESET  D1   // RESET
#define OLED_DC     D2   // Data/Command
#define OLED_CS     D8   // Chip select

SH1106 display(true, OLED_RESET, OLED_DC, OLED_CS);
SH1106Ui ui     ( &display );

Frames frames;
bool (*frameList[])(SH1106 *display, SH1106UiState* state, int x, int y) = { Frames::arialFrame, Frames::powerFrame };

Overlay overlay;
bool (*overlays[])(SH1106 *display, SH1106UiState* state)             = { Overlay::msOverlay };

void Oled_::begin() {

  ui.setTargetFPS(30);
  ui.setIndicatorPosition(BOTTOM);
  ui.setIndicatorDirection(LEFT_RIGHT);
  ui.setFrameAnimation(SLIDE_LEFT);
  ui.setFrames(frameList, frames.frameCount);  
  ui.setOverlays(overlays, overlay.overlaysCount);
  ui.init();
  display.flipScreenVertically();
}

int Oled_::update() {
  return ui.update();
}

void setOverlay() {
    
}

Oled_ &Oled_::getInstance() {
  static Oled_ instance;
  return instance;
}

Oled_ &Oled = Oled.getInstance();