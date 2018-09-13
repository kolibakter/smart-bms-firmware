#include <rgb_pwm_led.h>

class StatusLED {
public:
  enum State { IDLE, ERROR, RAINBOW };

  StatusLED(RGBPWMLED led, State init_state = State::IDLE);

  void set(const State state);

  StatusLED &operator<<(const State state) {
    set(state);
    return *this;
  }

private:
  RGBPWMLED led_;
  State state_;
  Ticker ticker_;

  // Constants
  static constexpr float idle_increment_ = 0.005f;
  static constexpr float rainbow_increment_ = 0.005f;

  // State variables
  float led_value_;

  unsigned int error_state_count_;
  bool idle_count_up_;
  enum RbState { RED_UP, GREEN_UP, BLUE_UP };
  RbState rainbow_state_;

  void idleCallback();
  void rainbowCallback();
  void errorCallback();

  void enter(const State state);
};
