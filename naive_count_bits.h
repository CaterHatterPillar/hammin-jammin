#ifndef NAIVE_COUNT_BITS_H
#define NAIVE_COUNT_BITS_H

unsigned naive_count_char(unsigned char c) {
  unsigned num_bits = 0;
  while(c) {
    num_bits += c & 1 ? 1 : 0;
    c >>= 1;
  }
  return num_bits;
}

unsigned naive_count_short(unsigned short s) {
  return naive_count_char(s >> 8) + naive_count_char(s);
}

unsigned naive_count_int(unsigned int i) {
  return naive_count_short(i);
}

unsigned naive_count_long(unsigned long l) {
  return naive_count_short(l >> 16) + naive_count_short(l);
}

unsigned naive_count_long_long(unsigned long long ll) {
  return naive_count_long(ll >> 32) + naive_count_long(ll);
}

void test_naive_count_bits() {
  assert(naive_count_char(0b10101010) == 4);
  assert(naive_count_char(0b11111111) == 8);
  assert(naive_count_char(0) == 0);
  
  assert(naive_count_short(0x00FF) == 8);
  assert(naive_count_int(0xFF00) == 8);
  assert(naive_count_long(0x0F0F0F0F) == 16);
  assert(naive_count_long_long(0xFFFFFFFF00000000) == 32);
}

#endif  // NAIVE_COUNT_BITS_H
