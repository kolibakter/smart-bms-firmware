#include "smartbms.h"

SmartBMS::SmartBMS() : ok_(true), status_led_({PC_6, PC_7, PC_8, 1.0f, true}) {}

void SmartBMS::run() {
  while (ok_) {
    status_led_ << StatusLED::RAINBOW;
    wait(20);
    status_led_ << StatusLED::IDLE;
    wait(20);
    status_led_ << StatusLED::ERROR;
    wait(20);
  }
}
