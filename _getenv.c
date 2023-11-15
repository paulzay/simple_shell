#include "shell.h"
/**
 * _getenv - custom getenv
 * @name: the variable name
 * Return: environment string
*/
cchar *_getenv(char *name)
{
	char **env_var = environ;

	while (*env_var)
	{
		if (strncmp(*env_var, name, _strlen(name))
			== 0 && (*env_var)[strlen(name)] == '=')
			return ((*env_var) + strlen(name) + 1);
		env_var++;
	}
	return (NULL);
}
