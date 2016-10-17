#ifndef BUILTIN_COUNT_BITS_H
#define BUILTIN_COUNT_BITS_H

unsigned builtin_count_bits_char(unsigned char c) {
  return __builtin_popcount(c);
}

unsigned builtin_count_bits_short(unsigned short s) {
  return __builtin_popcount(s);
}

unsigned builtin_count_bits_int(unsigned int i) {
  return __builtin_popcount(i);
}

unsigned builtin_count_bits_long(unsigned long l) {
  return __builtin_popcountl(l);
}

unsigned builtin_count_bits_long_long(unsigned long long ll) {
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
