#ifndef BUILTIN_H
#define BUILTIN_H

#include <stdint.h>

unsigned builtin_8(uint8_t c) {
  return __builtin_popcount(c);
}

unsigned builtin_16(uint16_t s) {
  return __builtin_popcount(s);
}

unsigned builtin_32(uint32_t l) {
  return __builtin_popcountl(l);
}

unsigned builtin_64(uint64_t ll) {
  return __builtin_popcountll(ll);
}

void test_builtin() {
  assert(builtin_8(0b10101010) == 4);
  assert(builtin_8(0b11111111) == 8);
  assert(builtin_8(0) == 0);
  
  assert(builtin_16(0x00FF) == 8);
  assert(builtin_32(0x0F0F0F0F) == 16);
  assert(builtin_64(0xFFFFFFFF00000000) == 32);
}

#endif  // BUILTIN_H
