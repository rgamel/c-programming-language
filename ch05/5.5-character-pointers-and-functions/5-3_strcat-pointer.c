#include <stdio.h>

void strcopy(char *s, char *t) {
  while ((*s++ = *t++))
    ;
}

void strct(char *s, char *t) {
  while (*s) {
    ++s;
  }

  strcopy(s, t);
}

int main(void) {
  char testbuf[128];

  char *test[] = {
      "", "1", "12", "123", "1234",
  };
  size_t numtests = sizeof test / sizeof test[0];
  size_t thistest;
  size_t inner;

  for (thistest = 0; thistest < numtests; thistest++) {
    for (inner = 0; inner < numtests; inner++) {
      strcopy(testbuf, test[thistest]);
      strct(testbuf, test[inner]);

      printf("[%s] + [%s] = [%s]\n", test[thistest], test[inner], testbuf);
    }
  }

  return 0;
}
