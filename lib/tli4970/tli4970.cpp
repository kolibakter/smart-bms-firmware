#include "tli4970.h"

TLI4970::TLI4970(SPI *spi, const PinName select_pin, const PinName overcurrent_pin)
    : spi_(spi), ss_(select_pin), ocd_(overcurrent_pin, PullUp) {
  frame_.data = 0;
}

void TLI4970::update() {
  ss_.select();
  frame_.data = spi_->write(0x00);
  ss_.deselect();
  // TODO: check parity
  if (frame_.status) {
    // TODO: Update status
  } else {
    overcurrent_ = frame_.ocd;
    updateCurrent();
  }
}

void TLI4970::updateCurrent() { current_ = (static_cast<float>(frame_.current) - 4096) / 80.0f; }
