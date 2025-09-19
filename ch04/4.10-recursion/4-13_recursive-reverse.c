#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main(void) {
  char s[] = "palindrome";

  printf("pre: %s\n", s);
  reverse(s);
  printf("post: %s\n", s);

  return 0;
}

void reverse(char s[]) {
  static int i, j;
  char t;

  if (i == 0)
    j = strlen(s) - 1;

  if (i < j) {
    t = s[i];
    s[i++] = s[j];
    s[j--] = t;

    reverse(s);
  }

  i = 0;
  j = 0;
}
