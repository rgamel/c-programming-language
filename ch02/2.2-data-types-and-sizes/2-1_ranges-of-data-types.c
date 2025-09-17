#include <limits.h>
#include <stdio.h>

int main(void) {
  printf("\n");
  printf("Bits of type char: %d\n\n", CHAR_BIT);

  printf("unsigned char max: %d\n\n", CHAR_MAX);
  printf("unsigned char min: %d\n\n", CHAR_MIN);

  printf("signed char max: %d\n\n", SCHAR_MAX);
  printf("signed char min: %d\n\n", SCHAR_MIN);

  printf("unsigned short max: %d\n\n", SHRT_MAX);
  printf("unsigned short min: %d\n\n", SHRT_MIN);

  printf("signed short max: %d\n\n", (unsigned)USHRT_MAX);

  printf("int max: %d\n\n", INT_MAX);
  printf("int min: %d\n\n", INT_MIN);

  printf("unsigned short max: %d\n\n", UINT_MAX);

  printf("long max: %ld\n\n", LONG_MAX);
  printf("long min: %ld\n\n", LONG_MIN);

  printf("unsigned long max: %lu\n\n", ULONG_MAX);

  return 0;
}
