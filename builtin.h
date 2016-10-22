#ifndef BUILTIN_H
#define BUILTIN_H

#include <stdint.h>

uint8_t builtin_8(uint8_t c) {
  return __builtin_popcount(c);
}

uint8_t builtin_16(uint16_t s) {
  return __builtin_popcount(s);
}

uint8_t builtin_32(uint32_t l) {
  return __builtin_popcountl(l);
}

uint8_t builtin_64(uint64_t ll) {
  return __builtin_popcountll(ll);
}

#endif  // BUILTIN_H
