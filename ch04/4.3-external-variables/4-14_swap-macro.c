#include <stdio.h>

#define swap(t, x, y)                                                          \
  {                                                                            \
    t temp;                                                                    \
    temp = x, x = y, y = temp;                                                 \
  }

int main(void) {
  char *px, *py;
  px = "hello";
  py = "world";
  printf("*px, *py BEFORE: %s %s\n", px, py);
  swap(char *, px, py);
  printf("*px, *py AFTER: %s %s\n", px, py);
  return 0;
}

