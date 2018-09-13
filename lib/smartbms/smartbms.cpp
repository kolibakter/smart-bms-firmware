#include "smartbms.h"

SmartBMS::SmartBMS() : ok_(true), status_led_({PC_6, PC_7, PC_8, 1.0f, true}), comm_(PA_2, PA_3) {
  status_led_ << StatusLED::RAINBOW;
}

void SmartBMS::run() {
  while (ok_) {
    comm_.write("sup?");
    wait(1);
  }
}
