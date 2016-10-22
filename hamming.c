#include <stdio.h>
#include <sys/time.h>

#include "builtin.h"
#include "kernighan.h"
#include "lookup.h"
#include "naive.h"
#include "popcnt.h"

#define bool uint8_t
#define false 0
#define true 1
bool expect_equal(uint8_t exp, uint8_t got) {
  bool equal = exp == got;
  if (!equal) {
    printf("Expected %d; got %d!\n", exp, got);
  }
  return equal;
}

bool test_hamming(uint8_t (*hamming)(uint64_t), const char *desc) {
  printf("Testing %s...\n", desc);
  bool success = true;
  success &= expect_equal(hamming(4711), 7);
  success &= expect_equal(hamming(0x4711), 6);
  success &= expect_equal(hamming(0), 0);
  success &= expect_equal(hamming(0xFFFFFFFFFFFFFFFF), 64);
  return success;
}

void profile_hamming(uint8_t (*hamming)(uint64_t), const char *desc) {
  struct timeval start;
  gettimeofday(&start, NULL);

  int i = 0;
  const int up_to = 10000;
  int total_hamming = 0;
  for(; i < up_to; ++i) {
    total_hamming += hamming(i);
  }

  struct timeval stop;
  gettimeofday(&stop, NULL);

  float elapsed = (stop.tv_sec - start.tv_sec) * 1000.0
    + (stop.tv_usec - start.tv_usec) / 1000.0;
  printf("%s: total hamming weight of %d numbers is %d and takes %f ms\n",
         desc, up_to, total_hamming, elapsed);
}

#define NUM_HAMMINGS 5
int main(int argc, char* argv[]) {
  uint8_t (*hammings[NUM_HAMMINGS])(uint64_t) = {
    builtin_64,
    kernighan_64,
    lookup_64,
    naive_64,
    popcnt_64
  };

  const char *descs[NUM_HAMMINGS] = {
    "Builtin",
    "Kernighan",
    "Lookup",
    "Naive",
    "Popcnt"
  };

  int i = 0;
  bool tests_pass = true;
  for (; i < NUM_HAMMINGS; ++i) {
    tests_pass &= test_hamming(hammings[i], descs[i]);
  }
  
  if (tests_pass) {
    for (i = 0; i < NUM_HAMMINGS; ++i) {
      profile_hamming(hammings[i], descs[i]);
    }
  } else {
    return 1;
  }
  
  return 0;
}
