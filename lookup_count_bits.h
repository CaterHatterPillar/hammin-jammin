#ifndef LOOKUP_COUNT_BITS_H
#define LOOKUP_COUNT_BITS_H

// http://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetNaive
static const unsigned char lookup_bit_count[256] = {
#   define B2(n) n,     n+1,     n+1,     n+2
#   define B4(n) B2(n), B2(n+1), B2(n+1), B2(n+2)
#   define B6(n) B4(n), B4(n+1), B4(n+1), B4(n+2)
    B6(0), B6(1), B6(1), B6(2)
};

unsigned lookup_count_bits_char(unsigned char c) {
  return lookup_bit_count[c];
}

unsigned lookup_count_bits_short(unsigned short s) {
  return lookup_bit_count[s >> 8] + lookup_bit_count[s];
}

unsigned lookup_count_bits_int(unsigned int i) {
  return lookup_count_bits_short(i);
}

unsigned lookup_count_bits_long(unsigned long l) {
  return lookup_bit_count[l & 0xFF]
    + lookup_bit_count[(l >> 8) & 0xFF]
    + lookup_bit_count[(l >> 16) & 0xFF]
    + lookup_bit_count[(l >> 24) & 0xFF];
}

unsigned lookup_count_bits_long_long(unsigned long long ll) {
  return lookup_count_bits_long(ll >> 32) + lookup_count_bits_long(ll);
}

void test_lookup_count_bits() {
  assert(lookup_count_bits_char(0b10101010) == 4);
  assert(lookup_count_bits_char(0b11111111) == 8);
  assert(lookup_count_bits_char(0) == 0);
  
  assert(lookup_count_bits_short(0x00FF) == 8);
  assert(lookup_count_bits_int(0xFF00) == 8);
  assert(lookup_count_bits_long(0x0F0F0F0F) == 16);
  assert(lookup_count_bits_long_long(0xFFFFFFFF00000000) == 32);
}

#endif  // LOOKUP_COUNT_BITS_H
