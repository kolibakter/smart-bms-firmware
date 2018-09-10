#pragma once

#include <led.h>
#include <mbed.h>

class RGBLED {
  LED red_, green_, blue_;

  struct Color {
    bool red, green, blue;
  };

public:
  static constexpr Color BLACK = Color{0, 0, 0};
  static constexpr Color RED = Color{1, 0, 0};
  static constexpr Color GREEN = Color{0, 1, 0};
  static constexpr Color BLUE = Color{0, 0, 1};
  static constexpr Color YELLOW = Color{1, 1, 0};
  static constexpr Color PURPLE = Color{1, 0, 1};
  static constexpr Color CYAN = Color{0, 1, 1};
  static constexpr Color WHITE = Color{1, 1, 1};

  RGBLED(const PinName red, const PinName green, const PinName blue, const bool active_low = false)
      : red_(red, active_low), green_(green, active_low), blue_(blue, active_low)  {}
  inline void set(const Color color) {
    red_ = color.red;
    blue_ = color.blue;
    green_ = color.green;
  };
};
