#include <stdio.h>

void squeeze(char s[], char c[]);

int main(void) {
  printf("\n");
  char s[] = "testing";
  printf("original: %s\n", s);
  squeeze(s, "t");
  printf("squeezed: %s\n", s);

  return 0;
}

void squeeze(char s[], char t[]) {
  int i, j, k;
  for (k = 0; t[k] != '\0'; k++) {
    for (i = j = 0; s[i] != '\0'; i++) {
      if (s[i] != t[k]) {
        s[j++] = s[i];
      }
    }
    s[j] = '\0';
  }
}
