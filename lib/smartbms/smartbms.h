#pragma once

#include <comm.h>
#include <status_led.h>

class SmartBMS {
public:
  SmartBMS();
  void run();

private:
  bool ok_;
  StatusLED status_led_;
  Comm comm_;
};
