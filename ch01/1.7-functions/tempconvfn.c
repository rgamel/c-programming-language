
#include <stdio.h>

#define LOWER 0   /* lower limit of table */
#define UPPER 300 /* upper limit of table */
#define STEP 20   /* step size */

int printtable(int fahr);
int formattemp(int fahr);

int main() {
  int fahr;

  for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
    formattemp(fahr);
  }
}

int printtable(int fahr) {
  for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
    formattemp(fahr);
  }
  return 0;
}

int formattemp(int fahr) {
  printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
  return 0;
}
