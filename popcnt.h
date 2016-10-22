#ifndef POPCNT_H
#define POPCNT_H

#include <stdint.h>

uint8_t popcnt_64(uint64_t);

uint8_t popcnt_8(uint8_t c) {
  return popcnt_64(c);
}

uint8_t popcnt_16(uint16_t s) {
  return popcnt_64(s);
}

uint8_t popcnt_32(uint32_t l) {
  return popcnt_64(l);
}

uint8_t popcnt_64(uint64_t ll) {
  uint64_t hamming = 0;
  __asm__ ("POPCNT %1, %0"
           : "=r"(hamming)
           : "r"(ll));
  return hamming;
}

#endif  // POPCNT_H
