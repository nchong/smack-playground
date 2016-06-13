// Expect: pass
// I expect this program to pass; however, smack fails this program (because
// strlen is modeled as an nondet function?). My current workaround is to
// provide my own implementation of strlen.

#include "smack.h"

#include <stdlib.h>
#include <string.h>

int main() {
  char *str = malloc(sizeof(char) * __VERIFIER_nondet_uint());
  __VERIFIER_assume(str != NULL);
  unsigned x = strlen(str);
  unsigned y = strlen(str);
  __VERIFIER_assert(x == y);
  return 0;
}

