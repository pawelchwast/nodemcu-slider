
#include "BatteryMonitor.h"
#define I2C_SDA 0 // custom SDA
#define I2C_SCL 2 // CUSTOM SCL

Adafruit_INA219 ina219;

void BatteryMonitor_::begin() {
  Wire.begin(I2C_SDA, I2C_SCL);
  ina219.begin();
  BatteryMonitor_::update();
}

void BatteryMonitor_::update() {
    this->busVoltage = ina219.getBusVoltage_V();
    this->current = ina219.getCurrent_mA();
    this->power = ina219.getPower_mW();
}

float BatteryMonitor_::getBusVoltage() {
  return this->busVoltage;
}

float BatteryMonitor_::getPower() {
  return this->power;
}

float BatteryMonitor_::getCurrent() {
  return this->current;
}

BatteryMonitor_ &BatteryMonitor_::getInstance() {
  static BatteryMonitor_ instance;
  return instance;
}

BatteryMonitor_ &BatteryMonitor = BatteryMonitor.getInstance();