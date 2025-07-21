#include <stdio.h>

int main () {
	float celsius, fahr;
	int upper, lower, step;
	
	lower = 0;
	upper = 300;
	step = 20;
	
	celsius = lower;
	
	printf("Celsius Fahr\n");
	while (celsius <= upper) {
		fahr = (9.0 / 5.0 * celsius) + 32;
		printf("%7.0f %5.0f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
