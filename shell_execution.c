#include "shell.h"

/**
 * exec - this executes a command
 * @argv: is an array of arguments
 */

void exec(char **argv)
{
	int p, status;

	if (!argv || !argv[0])
		return;
	p = fork();
	if (p == -1)
	{
		perror(_getenv("_"));
	}
	if (p == 0)
	{
		execve(argv[0], argv, environ);
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&status);
}
