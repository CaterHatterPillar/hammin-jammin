#include <assert.h>
#include <stdio.h>

#include "builtin_count_bits.h"
#include "lookup_count_bits.h"
#include "naive_count_bits.h"

int main(int argc, char* argv[]) {
  test_builtin_count_bits();
  test_naive_count_bits();
  test_lookup_count_bits();
  
  return 0;
}
