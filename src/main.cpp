#include <mbed.h>
#include <rgb_pwm_led.h>

int main() {
  RGBPWMLED status_led(PC_6, PC_7, PC_8, true);

  while (1) {
    status_led = {0.8f, 0.1f, 0.1f};
    wait_ms(333);
    status_led = {0.1f, 0.8f, 0.1f};
    wait_ms(333);
    status_led = {0.1f, 0.1f, 0.8f};
    wait_ms(333);
  }
}
