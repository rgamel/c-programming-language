#include <stdio.h>

#define MAXLEN 1000

int main(void) {
  int c, i = 0;
  char s[MAXLEN], t[MAXLEN];

  for (i = 0; i < MAXLEN - 1 && (c = getchar()) != EOF; ++i)
    s[i] = c;

  s[i] = '\0';

  return 0;
}

void escape(char s[], char t[]) {
  int i, j = 0;

  for (i = 0; s[i - j] != '\0'; i++) {
    switch (s[i - j]) {
    case '\n':
      t[i] = '\\';
      t[++i] = 'n';
      ++j;
      break;
    case '\t':
      t[i] = '\\';
      t[++i] = 't';
      break;
    default:
      t[i] = s[i - j];
      break;
    }
  }
  t[i] = '\0';
}

void unescape(char s[], char t[]) {
  int i, j = 0;

  for (i = 0; s[i + j] != '\0'; ++i) {
    switch (s[i + j]) {
    case '\\':
      switch (s[i + j + 1]) {
      case 'n':
        t[i] = '\n';
        ++j;
        ++i;
        break;
      case 't':
        t[i] = '\t';
        ++j;
        ++i;
        break;
      }
    default:
      t[i] = s[i + j];
      break;
    }
  }
  t[i] = '\0';
}
