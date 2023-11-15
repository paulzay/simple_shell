#include "shell.h"

/**
 * exec - this executes a command
 * @argv: is an array of arguments
 */

void exec(char **argv)
{
	int child_id;
	char *executable;
	int status;

	child_id = fork();

	if (child_id == 0)
	{
		executable = _which(argv[0]);
		if (executable != NULL)
		{
			execve(executable, argv, NULL);
			perror(argv[0]);
			exit(1);
		}
		else
		{
			perror(argv[0]);
			exit(1);
		}

	}
	else if (child_id > 0)
	{
		waitpid(child_id, &status, 0);
	}
	else
	{
		perror("fork failed");
		exit(1);
	}
}
