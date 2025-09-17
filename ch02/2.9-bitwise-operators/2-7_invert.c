#include <stdio.h>

unsigned invert(int x, int p, int n);
void printBinary(int n);

int main() {
  int test = 85;

  printBinary(test);
  printBinary(invert(test, 4, 3));
  return 0;
}

unsigned invert(int x, int p, int n) {
  int h = ~(~(~0 << n) << (p + 1 - n));
  return (x & h) | (~x & ~h);
}

void printBinary(int n) {
  int h = sizeof(n) * 8;
  for (int i = h - 1; i >= 0; i--) {
    int b = (n >> i) & 1;
    printf("%d", b);
  }
  printf("\n");
}
