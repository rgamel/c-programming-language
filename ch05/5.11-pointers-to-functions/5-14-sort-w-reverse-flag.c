#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define ALLOCSIZE 10000

char *lineptr[MAXLINES];
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void swap(void *v[], int, int);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
int getLine(char *s, int lim);
char *alloc(int n);
void qsort2(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(const char *s1, const char *s2);

int reverseCompare(void *, void *);

enum boolean { FALSE, TRUE };

int (*baseCompare)(void *, void *);

int (*compare)(void *, void *);

int main(int argc, char *argv[]) {

  int nlines, numeric = FALSE, reverse = FALSE;

  while (--argc > 0)
    if (strcmp(*++argv, "-n") == 0)
      numeric = TRUE;
    else if (strcmp(*argv, "-r") == 0)
      reverse = TRUE;
    else {
      printf("Usage: sort [-n] [-r]\n");
      return 1;
    }

  baseCompare = (int (*)(void *, void *))(numeric ? numcmp : strcmp);
  compare = reverse ? reverseCompare : baseCompare;

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort2((void **)lineptr, 0, nlines - 1, compare);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("input too big to sort\n");
    return 1;
  }
}

int numcmp(const char *s1, const char *s2) {
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;

  return 0;
}

void swap(void *v[], int i, int j) {
  void *temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

int getLine(char *s, int lim) {
  int c;
  char *original = s;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    *s++ = c;
  if (c == '\n')
    *s++ = c;
  *s = '\0';
  return s - original;
}

void writelines(char *lineptr[], int nlines) {
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

int reverseCompare(void *left, void *right) {
  return (*baseCompare)(right, left);
}

char *alloc(int n) {
  if (allocbuf + ALLOCSIZE - allocp >= n) // it fits
  {
    allocp += n;
    return allocp - n;
  } else
    return 0;
}

int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = getLine(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len - 1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

void qsort2(void *v[], int left, int right, int (*comp)(void *, void *)) {
  int i, last;
  if (left >= right)
    return;
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++)
    if ((*comp)(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort2(v, left, last - 1, comp);
  qsort2(v, last + 1, right, comp);
}
