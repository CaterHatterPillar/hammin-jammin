#ifndef BUILTIN_COUNT_BITS_H
#define BUILTIN_COUNT_BITS_H

#include <stdint.h>

unsigned builtin_count_bits_char(uint8_t c) {
  return __builtin_popcount(c);
}

unsigned builtin_count_bits_short(uint16_t s) {
  return __builtin_popcount(s);
}

unsigned builtin_count_bits_int(uint16_t i) {
  return __builtin_popcount(i);
}

unsigned builtin_count_bits_long(uint32_t l) {
  return __builtin_popcountl(l);
}

unsigned builtin_count_bits_long_long(uint64_t ll) {
  return __builtin_popcountll(ll);
}

void test_builtin_count_bits() {
  assert(builtin_count_bits_char(0b10101010) == 4);
  assert(builtin_count_bits_char(0b11111111) == 8);
  assert(builtin_count_bits_char(0) == 0);
  
  assert(builtin_count_bits_short(0x00FF) == 8);
  assert(builtin_count_bits_int(0xFF00) == 8);
  assert(builtin_count_bits_long(0x0F0F0F0F) == 16);
  assert(builtin_count_bits_long_long(0xFFFFFFFF00000000) == 32);
}

#endif  // BUILTIN_COUNT_BITS_H
