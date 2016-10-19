#ifndef KERNIGHAN_COUNT_BITS_H
#define KERNIGHAN_COUNT_BITS_H

#include <stdint.h>

unsigned kernighan_count_bits_char(uint8_t c) {
  unsigned num_bits = 0;
  for(; c; c & (c - 1)) {
    ++num_bits;
  }
  return num_bits;
}

unsigned kernighan_count_bits_short(uint16_t s) {
  return kernighan_count_char(s >> 8) + kernighan_count_char(s);
}

unsigned kernighan_count_bits_int(uint16_t i) {
  return kernighan_count_short(i);
}

unsigned kernighan_count_bits_long(uint32_t l) {
  return kernighan_count_short(l >> 16) + kernighan_count_short(l);
}

unsigned kernighan_count_bits_long_long(uint64_t ll) {
  return kernighan_count_long(ll >> 32) + kernighan_count_long(ll);
}

void test_kernighan_count_bits() {
  assert(kernighan_count_bits_char(0b10101010) == 4);
  assert(kernighan_count_bits_char(0b11111111) == 8);
  assert(kernighan_count_bits_char(0) == 0);
  
  assert(kernighan_count_bits_short(0x00FF) == 8);
  assert(kernighan_count_bits_int(0xFF00) == 8);
  assert(kernighan_count_bits_long(0x0F0F0F0F) == 16);
  assert(kernighan_count_bits_long_long(0xFFFFFFFF00000000) == 32);
}

#endif  // KERNIGHAN_COUNT_BITS_H
