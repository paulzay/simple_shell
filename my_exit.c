#include "shell.h"

/**
 * my_exit - exits the shell with or without a return of status n
 * @arv: array of words of the entered line
 */
void my_exit(char **arv)
{
	int status = 0;

	if (arv[1] != NULL)
	{
		char *endptr;
		long n = strtol(arv[1], &endptr, 10);

		if (*endptr != '\0' || n > INT_MAX || n < INT_MIN)
		{
			puts("Invalid argument");
			status = 2;
		}
		else
		{
			status = (int)n;
		}
	}
	freearv(arv);
	exit(status);
}

/**
 * freearv - this frees the array of pointers arv
 * @arv: array of pointers
 */

void freearv(char **arv)
{
	int i;

	if (!arv)
		return;

	for (i = 0; arv[i]; i++)
	{
		if (arv[i])
			free(arv[i]);
	}
	free(arv);
}
