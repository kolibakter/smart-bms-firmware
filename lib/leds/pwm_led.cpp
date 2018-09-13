#include "pwm_led.h"

PWMLED::PWMLED(const PinName pin_id, const bool active_low)
    : led_pin_(pin_id), active_low_(active_low) {
  off();
}

void PWMLED::setBrightness(const float brightness) {
  if (!active_low_)
    led_pin_.write(brightness);
  else
    led_pin_.write(1.0f - brightness);
}
