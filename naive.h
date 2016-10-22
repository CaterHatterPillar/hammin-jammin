#ifndef NAIVE_H
#define NAIVE_H

#include <stdint.h>

#define NAIVE(x)               \
  uint8_t hamming = 0;         \
  while(x) {                   \
    hamming += x & 1 ? 1 : 0;  \
    x >>= 1;                   \
  }                            \
  return hamming
  

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

#endif  // NAIVE_H
