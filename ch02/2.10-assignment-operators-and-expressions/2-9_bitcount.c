/*
 * In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
 * in x because if x is odd, the rightmost 1 becomes 0, if x is even the
 * rightmost zeroes become ones and the rightmost one becoming zero, and then
 * the &= operator clears the rightmost 1 bit in x and the rightmost 1-bits from
 * (x-1)
 * */

#include <stdio.h>

int bitcount(unsigned x);

int main(void) {
  printf("%d\n", bitcount(123));
  return 0;
}

int bitcount(unsigned x) {
  int b;

  for (b = 0; x != 0; x &= (x - 1)) {
    b++;
  }
  return b;
}
