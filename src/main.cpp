#include "led.h"
#include <mbed.h>

int main() {
  LED test_led(PC_6, true);

  // put your setup code here, to run once:

  test_led.off();

  while (1) {
    test_led.on();
    wait_ms(100);
    test_led.off();
    wait_ms(900);
  }
}
