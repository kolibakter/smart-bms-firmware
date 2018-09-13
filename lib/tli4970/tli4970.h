#pragma once

#include <mbed.h>

class TLI4970 {
  SPI* spi_;
  DigitalOut ss_;
  DigitalIn ocd_;

public:
  TLI4970(const SPI *spi, const PinName select_pin, const PinName overcurrent_pin) : spi_(spi), ss_(select_pin, true), ocd_(overcurrent_pin) {

  }
};
