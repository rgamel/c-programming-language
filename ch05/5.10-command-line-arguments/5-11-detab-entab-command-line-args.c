#include <stdio.h>
#define MAXSTOPS 1024

int stops[MAXSTOPS], stopcount;
int dfltsize = 4;

int istabstop(int col);
int atoi(char *s);
void parsestops(int argc, char *argv[]);
int dist2stop(int col);

int detab(int argc, char *argv[]) {
  int col, c, dist;

  parsestops(argc, argv);

  col = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      for (dist = dist2stop(col); dist > 0; --dist) {
        putchar(' ');
        ++col;
      }
    } else {
      putchar(c);
      if (c == '\n')
        col = 0;
      else if (c == '\b' && col > 0)
        --col;
      else
        ++col;
    }
  }
  return 0;
}

int dist2stop(int col) {
  int i;

  for (i = 0; i < stopcount; i++) {
    if (col < stops[i])
      return stops[i] - col;
  }
  return (dfltsize - (col % dfltsize));
}

int istabstop(int col) { return col > 0 && (dist2stop(col - 1) == 1); }

void parsestops(int argc, char *argv[]) {
  int i;

  stopcount = argc - 1;
  if (stopcount > MAXSTOPS) {
    printf("error: More than %d tap stops!\n", MAXSTOPS);
    return;
  }
  for (i = 1; i < argc; i++)
    stops[i - 1] = atoi(argv[i]) - 1;
}

int atoi(char *s) {
  int i, n = 0;

  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10 * n + (s[i] - '0');
  return n;
}

int entab(int argc, char *argv[]) {
  int col, c, nspace;

  parsestops(argc, argv);

  col = nspace = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\b' && col > 0) {
      --col;
      if (nspace > 0)
        --nspace;
      else
        putchar(c);
    } else if (nspace > 0 && istabstop(col)) {
      if (nspace == 1)
        putchar(' ');
      else
        putchar('\t');
      nspace = 0;
    }
    if (c == '\t') {
      putchar(c);
      nspace = 0;
      col = col + dist2stop(col);
    } else if (c == ' ') {
      ++col;
      ++nspace;
    } else if (c != '\b') {
      for (; 0 < nspace; --nspace)
        putchar(' ');
      putchar(c);
      if (c == '\n')
        col = 0;
      else
        ++col;
    }
  }
  return 0;
}
