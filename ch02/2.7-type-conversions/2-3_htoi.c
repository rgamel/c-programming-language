#include <ctype.h>
#include <stdio.h>

unsigned long htoi(char s[]);

int main(void) {
  printf("%ld\n", htoi("0xFA9C"));
  printf("%ld\n", htoi("0xFFFF"));
  printf("%ld\n", htoi("0x1111"));
  printf("%ld\n", htoi("0xBCDA"));

  return 0;
}

unsigned long htoi(char s[]) {
  unsigned long n = 0;
  int i = 0;

  /* skip 0x or 0X if present*/
  if (s[0] == '0' && tolower(s[1]) == 'x') {
    i = 2;
  }

  while (s[i] != '\0') {
    int c = tolower(s[i]);
    if (c >= '0' && c <= '9') {
      n = 16 * n + (c - '0');
    } else if (c >= 'a' && c <= 'f') {
      n = 16 * n + (c - 'a' + 10);
    }
    ++i;
  }

  return n;
}
