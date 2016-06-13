// Expect: fail
// Same as test2.c except using a global variable for A.
// smack can construct an array that falls inside some range
//
// Calling with "--bit-precise-pointers" causes a runtime-exception

#include "smack.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#define FLASH_ORIGIN 0x00000000
#define FLASH_SIZE   0x00001000
int in_flash(uint32_t addr) {
  return (FLASH_ORIGIN <= addr && addr < (FLASH_ORIGIN + FLASH_SIZE));
}

uint32_t *A = NULL;
int main() {
  uint32_t num = __VERIFIER_nondet_uint();
  A = malloc(sizeof(uint32_t)*num);
  __VERIFIER_assume(A != NULL);
  if (in_flash((uint32_t)A)) {
    __VERIFIER_assert(false);
  }
}
