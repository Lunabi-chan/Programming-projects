#include <stdio.h>
#include <stdarg.h>
#include <string.h>


void main(int argc, char* argv[]) {
	int h, i = 1;

	if (argc > 1) {

		(strcmp(argv[1], "-n")) == 0 ? h = 1, i = 2 : h = 0;
		(strcmp(argv[1], "-o")) == 0 ? h = 2, i = 2 : h = 0;

		printf("%d \n", h);

		for (; i < argc; i++) {
			if (h == 1) {
				printf("%d %s\n", i - 1, argv[i]);
			}
			else if (h == 2) {
				printf("- %s\n", argv[i]);
			}
			else {
				printf("%s\n", argv[i]);
			}
		}
	}
}