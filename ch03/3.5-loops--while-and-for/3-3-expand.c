#include <ctype.h>
#include <stdio.h>
#define MAXLEN 1000
#define TEST "a-b-c a-z0-9 -a-z"

char s[MAXLEN];

int isrange(int c1, int c2);
int expand(const char s1[], char s2[]);

int main(void) {
  printf("\n");

  expand(TEST, s);
  printf("%s\n", s);

  return 0;
}

int expand(const char s1[], char s2[]) {
  int s1i, s2i, order;
  char c, startc, endc;

  s1i = s2i = 0;

  while ((c = s1[s1i])) {
    if (c == '-' && s1i && (startc = s1[s1i - 1]) && (endc = s1[s1i + 1]) &&
        (order = isrange(startc, endc))) {
      if (order == 1) {
        for (c = startc + 1; c <= endc; ++c) {
          s2[s2i++] = c;
        }
      } else {
        for (c = startc - 1; c >= endc; --c) {
          s2[s2i++] = c;
        }
      }
      ++s1i;
    } else {
      s2[s2i++] = c;
    }

    ++s1i;
  }
  s2[s2i] = '\0';
  return s2i;
}

int isrange(int c1, int c2) {
  if (islower(c1) && islower(c2) || isupper(c1) && isupper(c2) ||
      isdigit(c1) && isdigit(c2)) {
    return c1 > c2 ? -1 : 1;
  }
  return 0;
}
