#include "shell.h"

/**
 * _which - function to return executable path
 * @command: the given command
 * Return: NULL
*/
char *_which(const char *command)
{
	char *path = _getenv("PATH");
	char *delim = ":";
	char *token = strtok(path, delim);
	char *full_path = (char *)malloc(strlen(command) + 1);

	if (full_path == NULL)
	{
		perror("malloc failed");
		exit(1);
	}
	while (token != NULL)
	{
		sprintf(full_path, "%s/%s", token, command);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		token = strtok(NULL, delim);
	}
	free(full_path);
	return (NULL);
}
