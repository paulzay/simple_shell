#include "shell.h"

char *append_bin(char *input) {
  if (strncmp(input, "/bin/", 5) == 0) {
    return input;
  }

  int input_len = strlen(input);
  char *output = malloc(input_len + 6);
  strcpy(output, "/bin/");
  strcat(output, input);
  return output;
}

/**
 * exec - this executes a command
 * @argv: is an array of arguments
 */


void exec(char **argv)
{
	int child_id;
	int status;
	char *path;

	if (!argv || !argv[0])
		return;

	path = append_bin(argv[0]);

	child_id = fork();

	if (child_id == 0)
	{
		execve(path, argv, environ);
		perror(argv[0]);
		exit(1);
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

/**
 * _realloc - Reallocates memory block
 * @ptr: previous pointer
 * @old_size: old size of previous pointer
 * @new_size: new size for our pointer
 * Return: New resized Pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;
	char *old;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	new = malloc(new_size);
	old = ptr;
	if (new == NULL)
		return (NULL);
	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			new[i] = old[i];
		free(ptr);
		for (i = old_size; i < new_size; i++)
			new[i] = '\0';
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			new[i] = old[i];
		free(ptr);
	}
	return (new);
}
