#include <stdio.h>

unsigned rightrot(unsigned x, int n);
void print_binary(unsigned x);

int main(void) {
  print_binary(245);
  print_binary(rightrot(245, 5));

  return 0;
}

unsigned rightrot(unsigned x, int n) {
  return (x >> n) | ((x & ~(~(0 << n)) << (sizeof(x) * 8 - n)));
}

void print_binary(unsigned int n) {
  int h = sizeof(n) * 8;
  for (int i = h - 1; i >= 0; i--) {
    int b = (n >> i) & 1;
    printf("%d", b);
  }
  printf("\n");
}
