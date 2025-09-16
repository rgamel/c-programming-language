#include <stdio.h>
#define MAXLINE 10000
int getLine(char s[], int max);

int main(void) {
  int len, i;
  char line[MAXLINE], longest[MAXLINE];

  while ((len = getLine(line, MAXLINE)) != 0) {
    if (len > 1) {
      for (i = len - 1; (line[i] == ' ' || line[i] == '\t' || line[i] == '\n');
           i--)
        ;
      line[++i] = '\n';
      line[++i] = '\0';
      printf("%s", line);
    }
  }
  return 0;
}

/* getline: read a line into s, return length */
int getLine(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && ((c = getchar()) != EOF && c != '\n'); ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    i++;
  } else if (c == EOF && i > 0) {
    s[i] = '\n';
    i++;
  }
  s[i] = '\0';
  return i;
}
