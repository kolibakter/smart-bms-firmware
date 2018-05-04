#include <mbed.h>

int main() {
  DigitalOut test_led(PA_5);

  // put your setup code here, to run once:

  while (1) {
    test_led = !test_led;
    wait_ms(500);
  }
}
