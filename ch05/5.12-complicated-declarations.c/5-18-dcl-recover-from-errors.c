#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXTOKEN 100
#define BUFSIZE 100

enum { NAME, PARENS, BRACKETS };
enum { OK, ERROR };

int dcl(void);
int dirdcl(void);
int gettoken(void);
int getch(void);
void ungetch(int c);

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
char buf[BUFSIZE];
int bufp = 0;

int main(void) {
  while (gettoken() != EOF) {
    strcpy(datatype, token);
    out[0] = '\0';
    if (dcl() == OK && tokentype == '\n')
      printf("%s: %s %s\n", name, out, datatype);
    else {
      if (tokentype != '\n')
        printf("syntax error\n");
      for (int c = '\0'; c != '\n' && c != EOF;)
        if ((c = getch()) == EOF)
          ungetch(c);
    }
  }
  return 0;
}

int gettoken(void) {
  int c;
  char *p = token;

  while ((c = getch()) == ' ' || c == '\t')
    ;
  if (c == '(') {
    if ((c = getch()) == ')') {
      strcpy(token, "()");
      return tokentype = PARENS;
    } else {
      ungetch(c);
      return tokentype = '(';
    }
  } else if (c == '[') {
    for (*p++ = c; (*p++ = getch()) != ']';)
      ;
    *p = '\0';
    return tokentype = BRACKETS;
  } else if (isalpha(c)) {
    for (*p++ = c; isalnum(c = getch());)
      *p++ = c;
    *p = '\0';
    ungetch(c);
    return tokentype = NAME;
  } else
    return tokentype = c;
}

int dcl(void) {
  int ns;
  for (ns = 0; gettoken() == '*';)
    ns++;
  if (dirdcl() == ERROR)
    return ERROR;
  while (ns-- > 0)
    strcat(out, " pointer to");
  return OK;
}

int dirdcl(void) {
  int type;
  if (tokentype == '(') {
    if (dcl() == ERROR)
      return ERROR;
    if (tokentype != ')') {
      printf("error: missing )\n");
      return ERROR;
    }
  } else if (tokentype == NAME)
    strcpy(name, token);
  else {
    printf("error: expected name or (dcl)\n");
    return ERROR;
  }
  while ((type = gettoken()) == PARENS || type == BRACKETS)
    if (type == PARENS)
      strcat(out, " function returning");
    else {
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
    }
  return OK;
}

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
