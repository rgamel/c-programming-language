#include <stdio.h>

int main() {
	int c, nl, t, s;

	nl = 0;
	t = 0;
	s = 0;

	nl = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			++nl;
		} 
		if (c == '\t') {
			++t;
		}
		if (c == ' ') {
			++s;
		}
	}

	printf("newlines %d\n", nl);
	printf("tabs %d\n", t);
	printf("spaces %d\n", s);
}

