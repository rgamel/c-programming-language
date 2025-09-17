#include <stdio.h>

int getLine(char s[], int lim);

int main(void) {
  int lim = 80;
  char s[lim];
}

/* simplified for the purposes of rewriting to avoid logical operators */
int getLine(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1; ++i) {
    c = getchar();
    if (c != '\n') {
      if (c != EOF) {
        s[i] = c;
      }
    }
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}
