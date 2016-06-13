Q: What does the warning (memory intrinsic length exceeds threshold (0); adding
quantifiers) emitted by smack mean? Does this introduce any unsoundness?

$ smack test0.c --entry-points f

Q: smack seems to treat strlen as a nondet function; not even as an
uninterpreted function which I would expect to return the same result for the
same input.
Q: Are there other workarounds than providing a concrete implementation of
strlen?

$ smack test1.c

Q: How are pointers treated when the flag "--bit-precise-pointers" is
enabled/disabled? test2.c does not seem to need the flag to fail; test3.c does.

$ smack test2.c --bit-precise-pointers
$ smack test3.c --bit-precise-pointers

Q: This variant of test2.c causes a runtime exception when using the flag
"--bit-precise-pointers":

$ smack test4.c --bit-precise-pointers
