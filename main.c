#include <assert.h>
#include <stdio.h>

#include "builtin.h"
#include "kernighan.h"
#include "lookup.h"
#include "naive.h"
#include "popcnt.h"

int main(int argc, char* argv[]) {
  test_builtin();
  test_kernighan();
  test_lookup();
  test_naive();
  test_popcnt();
  
  return 0;
}
