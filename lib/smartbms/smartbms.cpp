#include "smartbms.h"

SmartBMS::SmartBMS()
    : spi_(PA_7, PA_6, PA_5), status_led_({PC_6, PC_7, PC_8, 1.0f, true}), tli_(&spi_, PB_0, PC_5),
      battery_msg_(), battery_pub_(battery_topic_, &battery_msg_) {
  status_led_ << StatusLED::RAINBOW;
  spi_.frequency(1000000);
  spi_.format(16, 1);
  nh_.initNode();
  nh_.advertise(battery_pub_);
}

void SmartBMS::run() {
  while (ok_) {
    tli_.update();
    battery_msg_.header.seq++;
    battery_msg_.current = tli_.current_;
    battery_pub_.publish(&battery_msg_);
    nh_.loginfo("publishing");
    nh_.spinOnce();
    wait(1);
  }
}
