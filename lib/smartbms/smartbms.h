#pragma once

#include <rgb_pwm_led.h>

class SmartBMS {
public:
  SmartBMS();
  void run();

private:
  bool ok_;
  RGBPWMLED status_led_;
};
