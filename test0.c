// smack emits the warning:
//   warning: memory intrinsic length exceeds threshold (0); adding quantifiers.

#include "smack.h"

#include <stdlib.h>

void f(unsigned N) {
  const char **namespaces = calloc(N, sizeof(char *));
  __VERIFIER_assume(namespaces != NULL);
}
