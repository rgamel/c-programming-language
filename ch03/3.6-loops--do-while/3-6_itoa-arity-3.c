#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itoa(int n, char s[], int width);

int main(void) {
  char buffer[20];

  itoa(-543, buffer, 7);
  printf("Buffer:%s\n", buffer);

  return 0;
}

void itoa(int n, char s[], int width) {
  int i, sign;

  if ((sign = n) < 0)
    /* if negative, flip positive, but remember that it was originally negative
     */
    n = -n;

  i = 0;
  do {
    s[i++] = n % 10 + '0'; /* get next digit */
  } while ((n /= 10) > 0); /* then delete it */

  if (sign < 0)
    s[i++] = '-';

  while (i < width)
    s[i++] = ' ';

  reverse(s);

  s[i] = '\0';
}

void reverse(char s[]) {
  int c, i, j;

  printf("preview:%s", s);
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
  printf("postview:%s", s);
}
