#pragma once

#include "pwm_led.h"
#include <mbed.h>

class RGBPWMLED {
public:
  float brightness_;
  struct Color {
    float red, green, blue;
  };

  static constexpr Color BLACK = Color{0.0f, 0.0f, 0.0f};
  static constexpr Color WHITE = Color{1.0f, 1.0f, 1.0f};

  static constexpr Color RED = Color{1.0f, 0.0f, 0.0f};
  static constexpr Color YELLOW = Color{1.0f, 1.0f, 0.0f};
  static constexpr Color GREEN = Color{0.0f, 1.0f, 0.0f};
  static constexpr Color CYAN = Color{0.0f, 1.0f, 1.0f};
  static constexpr Color BLUE = Color{0.0f, 0.0f, 1.0f};
  static constexpr Color PURPLE = Color{1.0f, 0.0f, 1.0f};

  RGBPWMLED(const PinName red, const PinName green, const PinName blue,
            const float brightness = 1.0f, const bool active_low = false);

  inline void set(const Color color) {
    red_ = color.red * brightness_;
    blue_ = color.blue * brightness_;
    green_ = color.green * brightness_;
  };

  RGBPWMLED &operator=(const Color value) {
    set(value);
    return *this;
  }

private:
  PWMLED red_, green_, blue_;
};
