#include <ctype.h>
#include <stdio.h>

#define SIZE 100

int atoi(char *s) {
  int sign, n = 0;
  while (isspace(*s))
    s++;
  sign = (*s == '-') ? -1 : 1;
  if (*s == '+' || *s == '-')
    s++;
  while (isdigit(*s)) {
    n = 10 * n + (*s - '0');
    s++;
  }
  return sign * n;
}

void reverse(char *s) {
  char *p;
  int temp;
  p = s;
  while (*p) {
    p++;
  }
  p--;

  while (s <= p) {
    temp = *s;
    *s++ = *p;
    *p-- = temp;
  }
}

char *itoa(int n, char *s) {
  int sign;
  char *p = s;
  sign = (n < 0) ? -1 : 1;
  (sign < 0) ? n = -n : 0;
  while (n > 0) {
    *p++ = n % 10 + '0';
    n = n / 10;
  }
  (sign == -1) ? (*p++ = '-') : 0;
  *p = '\0';
  reverse(s);
  return s;
}

int strindex(char *s, char *t) {
  int tlen, count;
  char *p, *q, *r;
  q = t;
  while (*q++)
    ;
  q--;
  tlen = q - t;
  for (p = s; *p; p++) {
    count = 0;
    r = p;
    for (q = t; *q; q++, r++) {
      if (*r == *q)
        count++;
      else
        break;
    }
    if (count == tlen)
      return (int)(p - s);
  }
  return -1;
}
#define NUMBER '0'
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else
    buf[bufp++] = c;
}

int getop(char *s) {
  int c;
  while (isspace(*s = c = getch()))
    ;
  *(s + 1) = '\0';
  if (!isdigit(c) && c != '.')
    return c;

  if (isdigit(c))
    while (isdigit(*++s = c = getch()))
      ;

  if (c == '.')
    while (isdigit(*++s = c = getch()))
      ;

  *++s = '\0';
  if (c != EOF) {
    ungetch(c);
  }

  return NUMBER;
}

int main() {
  char str[SIZE];
  scanf("%s", str);
  printf("string = %s, number = %d\n", str, atoi(str));

  int num;
  scanf("%d", &num);
  printf("num = %d, string = %s\n", num, itoa(num, str));
}
