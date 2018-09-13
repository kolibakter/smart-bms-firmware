#include "status_led.h"
#include <mbed.h>

StatusLED::StatusLED(RGBPWMLED led, State init_state)
    : led_(led), state_(init_state), ticker_(), error_state_count_(0) {
  enter(state_);
}

void StatusLED::set(const State state) {
  if (state_ == state)
    return;
  enter(state);
}

void StatusLED::enter(const State state) {
  state_ = state;
  led_.off();
  ticker_.detach();
  switch (state) {
  case IDLE:
    led_value_ = 0.0f;
    idle_count_up_ = true;
    ticker_.attach_us(callback(this, &StatusLED::idleCallback), 10000);
    break;
  case ERROR:
    error_state_count_ = 0;
    ticker_.attach_us(callback(this, &StatusLED::errorCallback), 50000);
    break;
  case RAINBOW:
    led_value_ = 0.0f;
    rainbow_state_ = RED_UP;
    ticker_.attach_us(callback(this, &StatusLED::rainbowCallback), 10000);
    break;
  }
}

void StatusLED::idleCallback() {
  if (idle_count_up_) {
    led_value_ += idle_increment_;
    if (led_value_ > 1.0f)
      idle_count_up_ = false;
  } else {
    led_value_ -= idle_increment_;
    if (led_value_ < 0.0f)
      idle_count_up_ = true;
  }
  led_ = {0.0f, 0.0f, led_value_};
}

void StatusLED::errorCallback() {
  error_state_count_++;
  auto status = error_state_count_ % 15U;
  if ((status % 2) == 0) {
    led_ = RGBPWMLED::BLACK;
    return;
  }
  switch (status / 2) {
  case 1 ... 3:
    led_ = RGBPWMLED::RED;
    break;
  case 5 ... 7:
    led_ = RGBPWMLED::BLUE;
    break;
  default:
    led_ = RGBPWMLED::BLACK;
    break;
  }
}

void StatusLED::rainbowCallback() {
  led_value_ += rainbow_increment_;
  auto change_state = led_value_ > 1.0f;
  switch (rainbow_state_) {
  case RED_UP:
    led_ = {led_value_, 0.0f, 1.0f - led_value_};
    if (change_state)
      rainbow_state_ = GREEN_UP;
    break;
  case GREEN_UP:
    led_ = {1.0f - led_value_, led_value_, 0.0f};
    if (change_state)
      rainbow_state_ = BLUE_UP;
    break;
  case BLUE_UP:
    led_ = {0.0f, 1.0f - led_value_, led_value_};
    if (change_state)
      rainbow_state_ = RED_UP;
    break;
  }
  if (change_state)
    led_value_ = 0.0f;
}
