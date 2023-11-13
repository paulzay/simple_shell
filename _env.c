#include "shell.h"

void _env() {
	extern char **environ;

	while (*environ) {
		printf("%s\n", *environ);
		environ++;
	}
}
