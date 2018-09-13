#include "smartbms.h"

SmartBMS::SmartBMS()
    : ok_(true), status_led_({PC_6, PC_7, PC_8, 1.0f, true}), pub_int_("anint", &int_) {
  status_led_ << StatusLED::RAINBOW;
  nh_.initNode();
  nh_.advertise(pub_int_);
}

void SmartBMS::run() {
  while (ok_) {
    int_.data++;
    pub_int_.publish(&int_);
    nh_.spinOnce();
    wait(1);
  }
}
