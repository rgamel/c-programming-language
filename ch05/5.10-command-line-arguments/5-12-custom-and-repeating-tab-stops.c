#include <stdio.h>
#define MAXSTOPS 1024

int stops[MAXSTOPS], stopcount;
int dfltsize = 4;

int istabstop(int col);
int atoi(char *s);
void parsestops(int argc, char *argv[]);
int dist2stop(int col);
int max(int, int);

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

#define MAXARGS 1024
#define NOTSET -1

int custstops[MAXARGS], ncust;
int firstrepeating = NOTSET;
int repeatsize = 8;

int dist2stop(int col) {
  int rdist, cdist, i;

  rdist = col < firstrepeating
              ? (firstrepeating - col)
              : repeatsize - ((col - firstrepeating) % repeatsize);

  for (i = 0; i < ncust; i++) {
    if (col < custstops[i]) {
      cdist = custstops[i] - col;
      return rdist < cdist ? rdist : cdist;
    }
  }
  return rdist;
}

int istabstop(int col) { return col > 0 && (dist2stop(col - 1) == 1); }

void parsestops(int argc, char *argv[]) {

  char *vstr, first;
  int val, i;
  int maxcust = 0;

  if (argc > MAXARGS) {
    printf("error: more than %d arguments\n", MAXARGS);
    return;
  }
  ncust = 0;
  for (i = 1; i < argc; i++) {
    vstr = argv[i];
    first = *vstr;
    if (first == '-' || first == '+')
      vstr++;
    val = atoi(vstr);
    if (first == '-') {
      firstrepeating = val - 1;
    } else if (first == '+')
      repeatsize = val;
    else
      maxcust = max(maxcust, custstops[ncust++] = val - 1);
  }

  firstrepeating = firstrepeating == NOTSET ? maxcust : firstrepeating;
}

int max(int a, int b) { return a >= b ? a : b; }

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

int main(void) {
  printf("");
  return 0;
}
