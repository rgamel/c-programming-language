#include <stdio.h>
#define MAXLEN 1000

char s[MAXLEN];

int itoar(int n, char s[], int i) {
  if (n <= -10)
    i = itoar(n / 10, s, i);
  s[i++] = '0' - (n % 10);
  return i;
}

void itoa(int n, char s[]) {
  int i = 0;

  // if n is negative, append minus sign
  if (n < 0) {
    s[i++] = '-';
  } else {
    n = -n;
  }
  s[itoar(n, s, i)] = '\0';
}

int main(void) {
  itoa(12, s);
  printf("%s\n", s);
  itoa(24, s);
  printf("%s\n", s);
  itoa(-1987, s);
  printf("%s\n", s);
  return 0;
}
