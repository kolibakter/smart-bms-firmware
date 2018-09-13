#include "smartbms.h"

SmartBMS::SmartBMS() : ok_(true), status_led_(PC_6, PC_7, PC_8, true) {}

void SmartBMS::run() {
  while (ok_) {
    status_led_ = RGBPWMLED::RED;
    wait_ms(1000);
    status_led_ = RGBPWMLED::YELLOW;
    wait_ms(1000);
    status_led_ = RGBPWMLED::GREEN;
    wait_ms(1000);
    status_led_ = RGBPWMLED::CYAN;
    wait_ms(1000);
    status_led_ = RGBPWMLED::BLUE;
    wait_ms(1000);
    status_led_ = RGBPWMLED::PURPLE;
    wait_ms(1000);
  }
}
