#include <ctype.h>
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
int reverseCompare(void *, void *);
int numcmp(const char *s1, const char *s2);
int dircmp(const char *s1, const char *s2);
char *getField(char *, char *, int);

enum boolean { FALSE, TRUE };

int (*baseCompare)(void *, void *);
int (*compare)(void *, void *);
int caseInsensitive = FALSE, field = 0;
char a[MAXLEN], b[MAXLEN];

int main(int argc, char *argv[]) {
  int nlines, numeric, reverse, dirOrder, lexicographic;
  if ((nlines = readlines(lineptr, MAXLINES)) < 0) {
    printf("input too big to sort\n");
    return 1;
  }

  while (--argc > 0 && **++argv == '-') {
    field = 0;
    numeric = reverse = caseInsensitive = dirOrder = lexicographic = FALSE;
    while (*++*argv)
      if (field != 0)
        break;
      else
        switch (**argv) {
        case 'n':
          numeric = TRUE;
          break;
        case 'r':
          reverse = TRUE;
          break;
        case 'f':
          caseInsensitive = TRUE;
          break;
        case 'd':
          dirOrder = TRUE;
          break;
        case 'l':
          lexicographic = TRUE;
          break;
        default:
          if (!isdigit(**argv) && !(numeric || reverse || caseInsensitive ||
                                    dirOrder || lexicographic)) {
            argc = -1;
            break;
          } else if (isdigit(**argv))
            field = atoi(*argv);
          else
            argc = -1;
          break;
        }

    if (field < 0) {
      printf("error: field choices must be positive ints\n");
      return 1;
    }

    baseCompare = (int (*)(void *, void *))(numeric           ? numcmp
                                            : dirOrder        ? dircmp
                                            : caseInsensitive ? strcasecmp
                                                              : strcmp);
    compare = reverse ? reverseCompare : baseCompare;
    qsort2((void **)lineptr, 0, nlines - 1,
           reverse ? reverseCompare : baseCompare);
  }

  if (argc != 0) {
    printf("usage: sort [-n[#]] [-r[#]] [-f[#]] [-d[#]] [-l[$]]\n");
    return 1;
  }

  writelines(lineptr, nlines);
  return 0;
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
    if ((*comp)(getField(v[i], a, field), getField(v[left], b, field)) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort2(v, left, last - 1, comp);
  qsort2(v, last + 1, right, comp);
}

int dircmp(const char *s1, const char *s2) {
  int i = 0, j = 0;
  while (s1[i] || s2[i])
    if (isalnum(s1[i]) || isspace(s1[i]))
      if (isalnum(s2[j]) || isspace(s2[j]))
        if (caseInsensitive ? tolower(s1[i]) < tolower(s2[j]) : s1[i] < s2[j])
          return -1;
        else if (caseInsensitive ? tolower(s1[i]) > tolower(s2[j])
                                 : s1[i] > s2[j])
          return 1;
        else
          i++, j++;
      else
        j++;
    else
      i++;

  return 0;
}

char *getField(char *s, char *t, int n) {
  if (n <= 0)
    return s;
  int i = 0, j = 0;
  while (TRUE)
    if (s[i] == '\t' || s[i] == '\n' || s[i] == '\0')
      if (--n == 0) {
        t[j] = '\0';
        return t;
      } else if (s[i] == '\0')
        break;
      else {
        j = 0;
        s++;
      }
    else
      t[j++] = s[i++];

  return s;
}
