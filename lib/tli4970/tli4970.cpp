#include "tli4970.h"

TLI4970::TLI4970(SPI *spi, const PinName select_pin, const PinName overcurrent_pin)
    : spi_(spi), ss_(select_pin), ocd_(overcurrent_pin, PullUp) {
  frame_.data = 0;
}

void TLI4970::update() {
  ss_.select();
  frame_.data = spi_->write(0x00);
  ss_.deselect();
  if (!checkParity())
    return;
  if (frame_.status) {
    // TODO: Update status
  } else {
    overcurrent_ = frame_.ocd;
    updateCurrent();
  }
}

void TLI4970::updateCurrent() { current_ = (static_cast<float>(frame_.current) - 4096.f) / 80.f; }

bool TLI4970::checkParity() {
  // https://stackoverflow.com/a/21618038
  // This sensor uses odd parity
  // TODO: do not assume size of frame
  auto data = frame_.data;
  data ^= data >> 8;
  data ^= data >> 4;
  data ^= data >> 2;
  data ^= data >> 1;
  return static_cast<bool>(data & 1);
}
