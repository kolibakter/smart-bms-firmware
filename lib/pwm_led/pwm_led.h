#pragma once

#include <mbed.h>

class PWMLED {
  PwmOut led_pin_;
  bool active_low_;

public:
  PWMLED(const PinName pin_id, const bool active_low = false)
      : led_pin_(pin_id), active_low_(active_low) {}

  void setBrightness(const float brightness);

  inline void on() { setBrightness(1.0f); }
  inline void off() { setBrightness(0.0f); }

  PWMLED &operator=(const float value) {
    setBrightness(value);
    return *this;
  }
};
