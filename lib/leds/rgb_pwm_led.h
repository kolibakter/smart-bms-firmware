#pragma once

#include <mbed.h>
#include <pwm_led.h>

class RGBPWMLED {
  PWMLED red_, green_, blue_;

  struct Color {
    float red, green, blue;
  };

public:
  static constexpr Color BLACK = Color{0.0f, 0.0f, 0.0f};
  static constexpr Color WHITE = Color{1.0f, 1.0f, 1.0f};

  static constexpr Color RED = Color{1.0f, 0.0f, 0.0f};
  static constexpr Color YELLOW = Color{1.0f, 1.0f, 0.0f};
  static constexpr Color GREEN = Color{0.0f, 1.0f, 0.0f};
  static constexpr Color CYAN = Color{0.0f, 1.0f, 1.0f};
  static constexpr Color BLUE = Color{0.0f, 0.0f, 1.0f};
  static constexpr Color PURPLE = Color{1.0f, 0.0f, 1.0f};

  RGBPWMLED(const PinName red, const PinName green, const PinName blue,
            const bool active_low = false)
      : red_(red, active_low), green_(green, active_low), blue_(blue, active_low) {}

  inline void set(const Color color) {
    red_ = color.red;
    blue_ = color.blue;
    green_ = color.green;
  };

  RGBPWMLED &operator=(const Color value) {
    set(value);
    return *this;
  }
};
