#ifndef KERNIGHAN_H
#define KERNIGHAN_H

#include <stdint.h>

#define KERRIGAN(x)           \
  uint8_t hamming = 0;        \
  for(; x; x = x & (x - 1)) { \
    ++hamming;                \
  }                           \
  return hamming

uint8_t kernighan_8(uint8_t c) {
  KERRIGAN(c);
}

uint8_t kernighan_16(uint16_t s) {
  return kernighan_8(s >> 8) + kernighan_8(s);
}

uint8_t kernighan_32(uint32_t l) {
  return kernighan_16(l >> 16) + kernighan_16(l);
}

uint8_t kernighan_64(uint64_t ll) {
  KERRIGAN(ll);
}

void test_kernighan() {
  assert(kernighan_8(0b10101010) == 4);
  assert(kernighan_8(0b11111111) == 8);
  assert(kernighan_8(0) == 0);
  
  assert(kernighan_16(0x00FF) == 8);
  assert(kernighan_32(0x0F0F0F0F) == 16);
  assert(kernighan_64(0xFFFFFFFF00000000) == 32);
}

#endif  // KERNIGHAN_H
