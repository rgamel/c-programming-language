#include <stdio.h>

int lower(int c) { return ((c >= 'A') && (c <= 'Z')) ? c + 32 : c; }

int main(void) {
  printf("A to lower: %c\n", lower('A'));
  printf("B to lower: %c\n", lower('B'));
  printf("C to lower: %c\n", lower('C'));
  printf("Z to lower: %c\n", lower('Z'));
  printf("z to lower: %c\n", lower('z'));
  return 0;
}
