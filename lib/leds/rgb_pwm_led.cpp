#include "rgb_pwm_led.h"

RGBPWMLED::RGBPWMLED(const PinName red, const PinName green, const PinName blue,
                     const float brightness, const bool active_low)
    : brightness_(brightness), red_(red, active_low), green_(green, active_low),
      blue_(blue, active_low) {
  set(RGBPWMLED::BLACK);
}
