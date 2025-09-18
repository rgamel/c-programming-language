#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 13
#define COUNT 8

void reverse(char s[]);
void itoa(int n, char s[]);

int main(void) {
  int i, number[] = {15, -15, 6, -6, 1987, -1987, INT_MIN, INT_MAX};
  char s[MAXLEN];

  for (i = 0; i < COUNT; i++) {
    itoa(number[i], s);
    printf("%s\n", s);
  }

  return 0;
}

void itoa(int n, char s[]) {
  int i, sign = 1;

  if (n < 0) {
    sign = (-1);
  }
  i = 0;

  do {
    s[i++] = (n % 10) * sign + '0';
  } while ((n /= 10) != 0);

  if (sign < 0) {
    s[i++] = '-';
  }

  s[i] = '\0';

  reverse(s);
}

void reverse(char s[]) {
  int i, n;
  char line[MAXLEN];
  for (i = 0; s[i] != '\0'; ++i)
    ;
  n = 0;
  if (i == 0 || s[i] == '\0')
    line[i] = '\0';

  if (i > 0) {
    for (--i; i >= 0; --i) {
      line[i] = s[n];
      n++;
    }
    for (i = 0; line[i] != '\0'; i++)
      s[i] = line[i];
  }
}
