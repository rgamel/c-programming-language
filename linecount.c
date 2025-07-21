#include <stdio.h>

int main() {
	int c, nl;

	nl = 0;
	while ((c = getchar()) != EOF) {
		printf("hello %d\n", c);
		if (c == '\n') {
			printf("found newline\n");
			++nl;
		}
	}

	printf("%d\n", nl);
}
