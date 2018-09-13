#pragma once

#include <status_led.h>

class SmartBMS {
public:
  SmartBMS();
  void run();

private:
  bool ok_;
  StatusLED status_led_;
};
