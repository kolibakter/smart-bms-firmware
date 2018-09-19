#include "tli4970.h"

TLI4970::TLI4970(SPI *spi, const PinName select_pin, const PinName overcurrent_pin)
    : spi_(spi), ss_(select_pin), ocd_(overcurrent_pin, PullUp) {
  frame_.data = 0;
}

void TLI4970::update() {
  ss_.select();
  frame_.data = static_cast<uint16_t>(spi_->write(0x00));
  ss_.deselect();
  overcurrent_ = ocd_;
}
