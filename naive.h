#ifndef NAIVE_H
#define NAIVE_H

#include <stdint.h>

unsigned naive_8(uint8_t c) {
  unsigned num_bits = 0;
  while(c) {
    num_bits += c & 1 ? 1 : 0;
    c >>= 1;
  }
  return num_bits;
}

unsigned naive_16(uint16_t s) {
  return naive_8(s >> 8) + naive_8(s);
}

unsigned naive_32(uint32_t l) {
  return naive_16(l >> 16) + naive_16(l);
}

unsigned naive_64(uint64_t ll) {
  return naive_32(ll >> 32) + naive_32(ll);
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
