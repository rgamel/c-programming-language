
#include <stdio.h>

int any(char s[], char c[]);

int main(void) {
  char s[] = "testing";

  printf("\n");
  printf("original: %s\n", s);
  printf("location of any(g): %d\n", any(s, "g"));
  printf("location of any(tb): %d\n", any(s, "tb"));
  printf("location of any(b): %d\n", any(s, "b"));
  printf("\n");

  return 0;
}

int any(char s[], char t[]) {
  int i, j;
  for (i = 0; s[i] != '\0'; i++) {
    for (j = 0; t[j] != '\0'; j++) {
      if (s[i] == t[j])
        return i;
    }
  }
  return -1;
}
