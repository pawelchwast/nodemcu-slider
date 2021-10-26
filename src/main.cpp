

#include "BatteryMonitor.h"
#include "Oled.h"
#include <Ticker.h>

Ticker secondTick;
void batteryMonitorTicker() {
    BatteryMonitor.update();
}

void setup() {
  Serial.begin(115200);

  secondTick.attach(1, batteryMonitorTicker);

  BatteryMonitor.begin();
  Oled.begin();
  
}

void loop() {

  int remainingTimeBudget = Oled.update();

  if (remainingTimeBudget > 0) {
    // You can do some work here
    // Don't do stuff if you are below your
    // time budget.
    delay(remainingTimeBudget);
  }
}
