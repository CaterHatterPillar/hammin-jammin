#ifndef LOOKUP_H
#define LOOKUP_H

#include <stdint.h>

// http://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetNaive
static const uint8_t lookup[256] = {
#   define B2(n) n,     n+1,     n+1,     n+2
#   define B4(n) B2(n), B2(n+1), B2(n+1), B2(n+2)
#   define B6(n) B4(n), B4(n+1), B4(n+1), B4(n+2)
    B6(0), B6(1), B6(1), B6(2)
};

uint8_t lookup_8(uint8_t c) {
  return lookup[c];
}

uint8_t lookup_16(uint16_t s) {
  return lookup[s >> 8] + lookup[s];
}

uint8_t lookup_32(uint32_t l) {
  return lookup[l & 0xFF]
    + lookup[(l >> 8) & 0xFF]
    + lookup[(l >> 16) & 0xFF]
    + lookup[(l >> 24) & 0xFF];
}

uint8_t lookup_64(uint64_t ll) {
  return lookup_32(ll >> 32) + lookup_32(ll);
}

void test_lookup() {
  assert(lookup_8(0b10101010) == 4);
  assert(lookup_8(0b11111111) == 8);
  assert(lookup_8(0) == 0);
  
  assert(lookup_16(0x00FF) == 8);
  assert(lookup_32(0x0F0F0F0F) == 16);
  assert(lookup_64(0xFFFFFFFF00000000) == 32);
}

#endif  // LOOKUP_H
