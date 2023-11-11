#include "shell.h"

/**
 * my_exit - exits the shell with or without a return of status n
 * @arv: array of words of the entered line
 */
void my_exit(char **arv)
{
	int i;
	long n;

	if (arv[1])
	{
		char *endptr;
		n = strtol(arv[1], &endptr, 10);
		if (*endptr != '\0' || n < INT_MIN || n > INT_MAX)
		{
			puts("Invalid argument");
			freearv(arv);
			exit(2);
		}
		freearv(arv);
		exit((int)n);
	}
	for (i = 0; arv[i]; i++)
		free(arv[i]);
	free(arv);
	exit(0);
}
