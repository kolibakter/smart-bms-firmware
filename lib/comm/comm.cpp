#include "comm.h"

Comm::Comm(const PinName prog_tx, const PinName prog_rx) : prog_serial_(prog_tx, prog_rx) {}

void Comm::write(const char *data) {
  if (prog_serial_.writeable())
    prog_serial_.puts(data);
}
