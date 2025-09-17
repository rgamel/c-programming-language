#include <stdio.h>

#define MAXLINE 1000
char line[MAXLINE];

int getLine(void);

int main(void) {
  int len = 0;
  int t = 0;
  int brace = 0, bracket = 0, paren = 0, comment = 0;
  int squote = 1, dquote = 1;

  while ((len = getLine()) > 0) {
    t = 0;
    while (t < len) {
      if (line[t] == '[') {
        brace++;
      }
      if (line[t] == ']') {
        brace--;
      }
      if (line[t] == '(') {
        paren++;
      }
      if (line[t] == ')') {
        paren--;
      }
      if (line[t] == '\'') {
        squote *= -1;
      }
      if (line[t] == '"') {
        dquote *= -1;
      }
      if (line[t] == '/' && line[t + 1] == '*') {
        comment++;
      }
      if (line[t] == '*' && line[t + 1] == '/') {
        comment--;
      }
      t++;
    }
  }
  if (dquote != 1) {
    printf("Mismatched double quote");
  } else if (squote != 1) {
    printf("Mismatched single quote");
  } else if (paren != 0) {
    printf("Mismatched parens");
  } else if (brace != 0) {
    printf("Mismatched braces");
  } else if (bracket != 0) {
    printf("Mismatched brackets");
  } else if (comment != 0) {
    printf("Mismatched comments");
  } else {
    printf("Nothing unbalanced detected");
  }

  return 0;
}

/* getLine: specialized version */
int getLine() {
  int c, i;
  extern char line[];

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}
