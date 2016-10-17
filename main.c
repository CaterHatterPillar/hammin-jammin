#include <stdio.h>

unsigned count_bits(unsigned char c) {
  unsigned num_bits = 0;
  while(c > 0) {
    num_bits += c & 1 ? 1 : 0;
    c >>= 1;
  }
  return num_bits;
}

int main(int argc, char* argv[]) {
  unsigned char a = 0b10101010;
  unsigned char b = 0b00000001;
  unsigned char c = 0b11111111;
  printf("The number of bits set for these numbers are: %d %d %d\n",
         count_bits(a), count_bits(b), count_bits(c));

  return 0;
}
