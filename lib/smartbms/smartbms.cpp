#include "smartbms.h"

SmartBMS::SmartBMS()
    : status_led_({PC_6, PC_7, PC_8, 1.0f, true}), battery_pub_(battery_topic_, &battery_msg_) {
  status_led_ << StatusLED::RAINBOW;
  nh_.initNode();
  nh_.advertise(battery_pub_);
}

void SmartBMS::run() {
  while (ok_) {
    battery_msg_.header.seq++;
    battery_pub_.publish(&battery_msg_);
    nh_.spinOnce();
    wait(1);
  }
}
