#include <math.h>
#include <stdio.h>
#include <stdlib.h> /* for atof() - in K&R, math.h is referenced - this is an anachronism */

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char[]);
void push(double);
double pop(void);
void showtop(void);
void duplicatetop(void);
void swaptoptwo(void);
void clearstack(void);

int noprint = 0;

/* reverse Polish calculator */

int main(void) {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor\n");
      break;
    case '%':
      op2 = pop();
      if (op2 != 0.0)
        push(fmod(pop(), op2));
      else
        printf("error: zero modulo");
      break;
    case '?':
      showtop();
      break;
    case '#':
      duplicatetop();
      break;
    case '~':
      swaptoptwo();
      break;
    case '!':
      clearstack();
      break;
    case '$':
      push(sin(pop()));
      break;
    case '^':
      op2 = pop();
      push(pow(pop(), op2));
      break;
    case '@':
      push(exp(pop()));
      break;
    case '\n':
      if (!noprint)
        printf("\t%.8g\n", pop());
      noprint = 0;
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }

  return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[]) {
  int i, c, sign = 0;

  /* skip leading whitespace */
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;

  s[1] = '\0';
  if (!isdigit(c) && c != '.' && c != '-' && c != '+')
    return c; /* not a number */
  i = 0;
  if (c == '-' || c == '+')
    sign = c;

  if (isdigit(c) || sign > 0) /* collect integer part */
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;

  if (i == 1 && sign != 0) {
    ungetch(c);
    return sign;
  }

  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

void showtop(void) {
  noprint = 1;
  if (sp > 0)
    printf("top element: %8g\n", val[sp - 1]);
  else
    printf("empty stack\n");
}

void duplicatetop(void) {
  noprint = 1;
  if (sp > 0 && sp < MAXOP - 1) {
    push(val[sp - 1]);
  }
}
void swaptoptwo(void) {
  noprint = 1;

  double op1, op2;
  op1 = pop();
  op2 = pop();

  push(op1);
  push(op2);
}

void clearstack() { sp = 0; }
