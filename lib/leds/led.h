#pragma once

#include <mbed.h>

class LED {
  DigitalOut led_pin_;
  bool active_low_;

public:
  LED(const PinName pin_id, const bool active_low = false)
      : led_pin_(pin_id, active_low), active_low_(active_low) {}

  inline void invert() { led_pin_ = !led_pin_; }
  inline void set(const bool state) { led_pin_ = state ^ active_low_; };

  inline void on() { set(true); }
  inline void off() { set(false); }

  LED &operator=(const int value) {
    set(value);
    return *this;
  }
};
