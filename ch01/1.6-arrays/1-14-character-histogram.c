#include <stdio.h>

#define ASCII 128

int main () {
	int c = EOF;
	int i, j, max_freq = 0;
	int freq[ASCII];

	// initialize array with 0s
	for (i = 0; i< ASCII; ++i) freq[i] = 0;
	
	// collect chars
	while((c = getchar()) != EOF) {
		if (c != ' ' && c != '\t' && c != '\n') {
			++freq[c];
		}
	}

	// find max_freq
	for (i = 0; i < ASCII; ++i) {
		if (freq[i] > max_freq) {
			max_freq = freq[i];
		}
	}
	

	printf("HISTOGRAM: ");
	printf("%d \n", max_freq);

	for (i = 0; i < ASCII; i++) {
		if (freq[i] > 0){
			printf("| %c | ", i);

			for (j = 0; j < freq[i]; j++) {
				putchar('*');
			}

			putchar('\n');
		}
	}

	return 0;
}

