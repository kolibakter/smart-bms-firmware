#pragma once
#include <mbed.h>

class Comm {
public:
  Comm(const PinName prog_rx, const PinName prog_tx);

  void write(const char *data);

private:
  Serial prog_serial_;
};
