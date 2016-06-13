// Expect: fail
// Converse case to test2.c; smack can construct an array that falls *outside*
// some range; needs "--bit-precise-pointers" flag

#include "smack.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#define FLASH_ORIGIN 0x00000000
#define FLASH_SIZE   0x00001000
int in_flash(uint32_t addr) {
  return (FLASH_ORIGIN <= addr && addr < (FLASH_ORIGIN + FLASH_SIZE));
}

int main() {
  uint32_t num = __VERIFIER_nondet_uint();
  uint32_t *A = malloc(sizeof(uint32_t)*num);
  __VERIFIER_assume(A != NULL);
  if (!in_flash((uint32_t)A)) {
    __VERIFIER_assert(false);
  }
}
