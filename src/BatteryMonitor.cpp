
#include "BatteryMonitor.h"
#define I2C_SDA 0 // custom SDA
#define I2C_SCL 2 // CUSTOM SCL

Adafruit_INA219 ina219;

void BatteryMonitor_::begin() {
  Wire.begin(I2C_SDA, I2C_SCL);
  ina219.begin();
  BatteryMonitor_::doStuff();
}

void BatteryMonitor_::doStuff() {
//   float shuntvoltage = 0;
//   float busvoltage = 0;
//   float current_mA = 0;
//   float loadvoltage = 0;
//   float power_mW = 0;

//   this->shuntvoltage = ina219.getShuntVoltage_mV();
this->busVoltage = ina219.getBusVoltage_V();
//   current_mA = ina219.getCurrent_mA();
//   power_mW = ina219.getPower_mW();
//   loadvoltage = busvoltage + (shuntvoltage / 1000);
//   Serial.print("Bus Voltage:   "); Serial.print(this->busVoltage); Serial.println(" V");
}

float BatteryMonitor_::getBusVoltage() {
  return this->busVoltage;
}

BatteryMonitor_ &BatteryMonitor_::getInstance() {
  static BatteryMonitor_ instance;
  return instance;
}

BatteryMonitor_ &BatteryMonitor = BatteryMonitor.getInstance();