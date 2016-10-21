#ifndef NAIVE_H
#define NAIVE_H

#include <stdint.h>

#define NAIVE(x)               \
  uint8_t num_bits = 0;        \
  while(x) {                   \
    num_bits += x & 1 ? 1 : 0; \
    x >>= 1;                   \
  }                            \
  return num_bits
  

uint8_t naive_8(uint8_t c) {
  NAIVE(c);
}

uint8_t naive_16(uint16_t s) {
  return naive_8(s >> 8) + naive_8(s);
}

uint8_t naive_32(uint32_t l) {
  return naive_16(l >> 16) + naive_16(l);
}

uint8_t naive_64(uint64_t ll) {
  NAIVE(ll);
}

void test_naive() {
  assert(naive_8(0b10101010) == 4);
  assert(naive_8(0b11111111) == 8);
  assert(naive_8(0) == 0);
  
  assert(naive_16(0x00FF) == 8);
  assert(naive_32(0x0F0F0F0F) == 16);
  assert(naive_64(0xFFFFFFFF00000000) == 32);
}

#endif  // NAIVE_H
