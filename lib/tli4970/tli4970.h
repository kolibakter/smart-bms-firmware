#pragma once

#include <chip_select.h>
#include <mbed.h>

class TLI4970 {
public:
  union Frame {
    uint16_t data;
    struct {
      uint16_t status : 1, parity : 1;
    };

    struct {
      uint16_t : 2, ocd : 1, current : 13;
    };

    struct {
      uint16_t : 2, hw_error : 1, overload_error : 1, temp_error : 1, comm_error : 1;
    };
  };

  TLI4970(SPI *spi, const PinName select_pin, const PinName overcurrent_pin);

  void update();
  Frame frame_;

private:
  // Comm
  SPI *spi_;
  ChipSelect ss_;
  DigitalIn ocd_;

  // Storage
  bool overcurrent_ = false;
};
