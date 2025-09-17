#include <stdio.h>
#define MAXLINE 1000
#define TAB 4

char line[MAXLINE];
int getLine(void); // from book

int main() {
  int i, t;
  int spacecount, len;

  while ((len = getLine()) > 0) {
    spacecount = 0;
    for (i = 0; i < len; i++) {
      if (line[i] != ' ')
        spacecount = 0;
      if (spacecount == TAB) {
        // replace spaces with tab
        i -= (TAB - 1);
        len -= (TAB - 1);
        line[i] = '\t';
        for (t = i + 1; t < len; t++)
          line[t] = line[t + 3];
        spacecount = 0;
        line[len] = '\0';
      }
    }
    printf("%s", line);
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
