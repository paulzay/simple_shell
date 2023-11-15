#include "shell.h"

/**
 * _env - function to get the environment
 * Return: no return
*/
void _env(void)
{
	char **env_var = environ;

	while (*env_var)
	{
		write(STDOUT_FILENO, *env_var, strlen(*env_var));
		write(STDOUT_FILENO, "\n", 1);
		env_var++;
	}
}
