#include <mbed.h>

class ChipSelect : DigitalOut {
public:
  ChipSelect(const PinName &pin) : DigitalOut(pin, true) {}
  inline void select() { write(0); }
  inline void deselect() { write(1); }
};
