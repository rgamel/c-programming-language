#include <stdio.h>

unsigned int setbits(unsigned x, int p, int n, unsigned y) {
  unsigned int mask;

  mask = ~(~0 << n);
  mask <<= p + 1 - n;

  y <<= p + 1 - n;

  y &= mask;
  x &= ~mask;

  return x | y;
}

int main(void) {
  printf("%d\n", setbits(93, 4, 3, 211));
  return 0;
}
