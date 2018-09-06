#include <mbed.h>
#include <pwm_led.h>

int main() {
  PWMLED status_led(PC_6, true);

  while (1) {
    status_led = 0.8f;
    wait_ms(100);
    status_led = 0.1f;
    wait_ms(900);
  }
}
