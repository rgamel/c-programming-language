# include <stdio.h>

int main() {
	int c;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			while ((c = getchar()) == ' ') {
				// do nothing
			};

			putchar(' ');

			if ((c = getchar()) == EOF) {
				break;
			}	
		}

		// not a blank
		putchar(c);
	}
}
