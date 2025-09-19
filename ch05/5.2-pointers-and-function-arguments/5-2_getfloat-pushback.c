#include <ctype.h>
#include <math.h>
#include <stdio.h>

#define MAX 10

int getch(void);
void ungetch(int);

double getfloat(int *pn) {
  int c, i, sign;

  /* skip whitespace */
  while (isspace(c = getch()))
    ;

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');

  if (c == '.') {
    c = getch();
    for (i = 1; isdigit(c); c = getch(), i++)
      *pn += (double)(c - '0') / pow(10, i);
  }

  *pn *= sign;

  if (c != EOF)
    ungetch(c);

  return c;
}

int main(void) {
  int i, num[MAX];
  int val;

  for (i = 0; i < MAX && (val = getfloat(&num[i])) != EOF; i++)
    printf("num[%d] = %d, \nt value returned: %d (%s)\n", i, num[i], val,
           val != 0 ? "number" : "not a number");

  return 0;
}

int bufp = 0;
int buf[MAX];

int getch(void) { return bufp > 0 ? buf[--bufp] : getchar(); }

void ungetch(int c) {
  if (bufp < MAX)
    buf[bufp++] = c;
}
