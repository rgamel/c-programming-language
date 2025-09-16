#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest line */
int main(void) {
  char line[MAXLINE];
  char longest[MAXLINE]; /* longest line saved here */
  char temp[MAXLINE];
  int len, max, prevmax, getmore;

  max = prevmax = getmore = 0;
  while ((len = getLine(line, MAXLINE)) > 0) {
    if (line[len - 1] != '\n') {
      if (getmore == 0) {
        copy(temp, line);
      }

      prevmax += len;
      if (max < prevmax) {
        max = prevmax;
      }
      getmore = 1;
    } else {
      if (getmore == 1) {
        if (max < prevmax + len) {
          max = prevmax + len;
          copy(longest, temp);
          longest[MAXLINE - 2] = '\n';
        }
        getmore = 0;
      } else if (max < len) {
        max = len;
        copy(longest, line);
      }
      prevmax = 0;
    }
  }
  if (max > 0) {
    printf("%s", longest);
    printf("len = %d\n", max);
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
    ++i;
  } else if (c == EOF && i > 0) {
    s[i] = '\n';
    ++i;
  }
  s[i] = '\0';
  return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
