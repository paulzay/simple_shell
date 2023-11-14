#include "shell.h"

/**
 * exec - this executes a command
 * @argv: is an array of arguments
 */

void exec(char **argv)
{
	int child_id;
	char *executable;

	if (argv[0] && _strlen(argv[0]) < 2) {
		return;
	}
	executable = _which(argv[0]);
	if (executable == NULL) {
		printf("hsh %s: command not found\n", argv[0]);
		return;
	}
	child_id = fork();
	if (child_id == -1) {
		perror("fork failed");
		exit(1);
	}
	if (child_id == 0) {
		execve(executable, argv, NULL);
		perror(argv[0]);
		exit(1);
	} else {
		if (waitpid(child_id, NULL, 0) == -1) {
			perror("waitpid failed");
			exit(1);
		}
	}
}
