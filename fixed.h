#ifndef FIXED_H
#define FIXED_H

#include <stdint.h>

uint8_t fixed_64(uint64_t ll);

uint8_t fixed_8(uint8_t c) {
  return fixed_64(c);
}

uint8_t fixed_16(uint16_t s) {
  return fixed_64(s);
}

uint8_t fixed_32(uint32_t l) {
  return fixed_64(l);
}

uint8_t fixed_64(uint64_t ll) {
  ll = (ll & 0x5555555555555555) + ((ll >> 1) & 0x5555555555555555);  // 0101
  ll = (ll & 0x3333333333333333) + ((ll >> 2) & 0x3333333333333333);  // 0011
  ll = (ll & 0x0f0f0f0f0f0f0f0f) + ((ll >> 4) & 0x0f0f0f0f0f0f0f0f);
  ll = (ll & 0x00ff00ff00ff00ff) + ((ll >> 8) & 0x00ff00ff00ff00ff);
  ll = (ll & 0x0000ffff0000ffff) + ((ll >> 16) & 0x0000ffff0000ffff);
  return (ll & 0x00000000ffffffff) + ((ll >> 32) & 0x00000000ffffffff);
}

#endif  // FIXED_H
