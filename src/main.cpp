#include "led.h"
#include <mbed.h>

int main() {
  LED test_led(PA_5);

  // put your setup code here, to run once:

  while (1) {
    test_led.Invert();
    wait_ms(100);
  }
}
