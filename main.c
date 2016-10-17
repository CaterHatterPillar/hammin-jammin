#include <assert.h>
#include <stdio.h>

unsigned count_bits_char(unsigned char c) {
  unsigned num_bits = 0;
  while(c) {
    num_bits += c & 1 ? 1 : 0;
    c >>= 1;
  }
  return num_bits;
}

unsigned count_bits_short(unsigned short s) {
  return count_bits_char(s >> 8) + count_bits_char(s);
}

unsigned count_bits_int(unsigned int i) {
  return count_bits_short(i);
}

unsigned count_bits_long(unsigned long l) {
  return count_bits_short(l >> 16) + count_bits_short(l);
}

unsigned count_bits_long_long(unsigned long long ll) {
  return count_bits_long(ll >> 32) + count_bits_long(ll);
}

int main(int argc, char* argv[]) {
  assert(count_bits_char(0b10101010) == 4);
  assert(count_bits_char(0b11111111) == 8);
  assert(count_bits_char(0) == 0);
  
  assert(count_bits_short(0x00FF) == 8);
  assert(count_bits_int(0xFF00) == 8);
  assert(count_bits_long(0x0F0F0F0F) == 16);
  assert(count_bits_long_long(0xFFFFFFFF00000000) == 32);

  return 0;
}
