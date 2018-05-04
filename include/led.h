#pragma once

#include <mbed.h>

class LED {
  DigitalOut led_pin_;

public:
  LED(PinName pin_id) : led_pin_(pin_id){};
  void Invert() { led_pin_ = !led_pin_; }
};
