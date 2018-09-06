#include "rgb_led.h"
#include <mbed.h>

int main() {
  RGBLED status_led(PC_6, PC_7, PC_8, true);

  while (1) {
    status_led.set(RGBLED::WHITE);
    wait_ms(100);
    status_led.set(RGBLED::BLACK);
    wait_ms(900);
  }
}
