#pragma once

#include <chip_select.h>
#include <mbed.h>

class TLI4970 {
public:
  union Frame {
    uint16_t data;
    struct {
      uint16_t : 14, parity : 1, status : 1;
    };

    struct {
      uint16_t current : 13, ocd : 1;
    };

    struct {
      uint16_t : 10, comm_error : 1, temp_error : 1, overload_error : 1, hw_error : 1;
    };
  };

  TLI4970(SPI *spi, const PinName select_pin, const PinName overcurrent_pin);

  void update();

  // Storage
  bool overcurrent_ = false;
  float current_ = 0.0f;

private:
  // Comm
  SPI *spi_;
  ChipSelect ss_;
  DigitalIn ocd_;

  // Storage
  Frame frame_;

  // Functions
  void updateCurrent();
};
