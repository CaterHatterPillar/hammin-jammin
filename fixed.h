#ifndef FIXED_H
#define FIXED_H

#include <stdint.h>

uint8_t fixed_8(uint8_t c) {
  c = (c & 0x55) + ((c >> 1) & 0x55);
  c = (c & 0x33) + ((c >> 2) & 0x33);
  return (c & 0x0f) + ((c >> 4) & 0x0f);
}

uint8_t fixed_16(uint16_t s) {
  s = (s & 0x5555) + ((s >> 1) & 0x5555);
  s = (s & 0x3333) + ((s >> 2) & 0x3333);
  s = (s & 0x0f0f) + ((s >> 4) & 0x0f0f);
  return (s & 0x00ff) + ((s >> 8) & 0x00ff);
}

uint8_t fixed_32(uint32_t l) {
  l = (l & 0x55555555) + ((l >> 1) & 0x55555555);
  l = (l & 0x33333333) + ((l >> 2) & 0x33333333);
  l = (l & 0x0f0f0f0f) + ((l >> 4) & 0x0f0f0f0f);
  l = (l & 0x00ff00ff) + ((l >> 8) & 0x00ff00ff);
  return (l & 0x0000ffff) + ((l >> 16) & 0x0000ffff);
}

uint8_t fixed_64(uint64_t ll) {
  ll = (ll & 0x5555555555555555) + ((ll >> 1) & 0x5555555555555555);
  ll = (ll & 0x3333333333333333) + ((ll >> 2) & 0x3333333333333333);
  ll = (ll & 0x0f0f0f0f0f0f0f0f) + ((ll >> 4) & 0x0f0f0f0f0f0f0f0f);
  ll = (ll & 0x00ff00ff00ff00ff) + ((ll >> 8) & 0x00ff00ff00ff00ff);
  ll = (ll & 0x0000ffff0000ffff) + ((ll >> 16) & 0x0000ffff0000ffff);
  return (ll & 0x00000000ffffffff) + ((ll >> 32) & 0x00000000ffffffff);
}

#endif  // FIXED_H
