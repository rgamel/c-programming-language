#include <stdio.h>

int main() {
	int blanks, tabs, nl, c;

	blanks = 0;
	tabs = 0;
	nl = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			++blanks;
		} else if (c == '\t') {
			++tabs;	
		} else if (c == '\n') {
			++nl;
		}

	}
	printf("\nblanks: %d\ntabs: %d\nnl: %d\n", blanks, tabs, nl);
}

