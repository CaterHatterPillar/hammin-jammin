#ifndef POPCNT_COUNT_BITS_H
#define POPCNT_COUNT_BITS_H

#include <stdint.h>

unsigned popcnt_count_bits_long_long(uint64_t);

unsigned popcnt_count_bits_char(uint8_t c) {
  return popcnt_count_bits_long_long(c);
}

unsigned popcnt_count_bits_short(uint16_t s) {
  return popcnt_count_bits_long_long(s);
}

unsigned popcnt_count_bits_int(uint16_t i) {
  return popcnt_count_bits_long_long(i);
}

unsigned popcnt_count_bits_long(uint32_t l) {
  return popcnt_count_bits_long_long(l);
}

unsigned popcnt_count_bits_long_long(uint64_t ll) {
  uint64_t num_bits = 0;
  __asm__ ("POPCNT %1, %0"
           : "=r"(num_bits)
           : "r"(ll));
  return num_bits;
}

void test_popcnt_count_bits() {
  assert(popcnt_count_bits_char(0b10101010) == 4);
  assert(popcnt_count_bits_char(0b11111111) == 8);
  assert(popcnt_count_bits_char(0) == 0);
  
  assert(popcnt_count_bits_short(0x00FF) == 8);
  assert(popcnt_count_bits_int(0xFF00) == 8);
  assert(popcnt_count_bits_long(0x0F0F0F0F) == 16);
  assert(popcnt_count_bits_long_long(0xFFFFFFFF00000000) == 32);
}

#endif  // POPCNT_COUNT_BITS_H
