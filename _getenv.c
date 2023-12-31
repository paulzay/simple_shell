#include "shell.h"
/**
 * _getenv - custom getenv
 * @name: the variable name
 * Return: environment string
*/
char *_getenv(char *name)
{
	char **env_var = environ;

	while (*env_var)
	{
		if (strncmp(*env_var, name, _strlen(name))
			== 0 && (*env_var)[_strlen(name)] == '=')
			return ((*env_var) + _strlen(name) + 1);
		env_var++;
	}
	return (NULL);
}
