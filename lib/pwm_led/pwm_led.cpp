#include "pwm_led.h"

void PWMLED::setBrightness(const float brightness) {
  if (!active_low_)
    led_pin_.write(brightness);
  else
    led_pin_.write(1.0f - brightness);
}
