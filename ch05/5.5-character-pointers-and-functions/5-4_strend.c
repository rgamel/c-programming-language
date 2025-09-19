#include <stdio.h>

int strend(char *s, char *t) {
  char *cs, *ct;
  do {
    for (cs = s, ct = t; *cs == *ct; cs++, ct++)
      if (*cs == '\0')
        return 1;
  } while (*s++ != '\0');
  return 0;
}

int main(void) {
  printf("%d\n", strend("hellow, world!", "world!"));
  return 0;
}
