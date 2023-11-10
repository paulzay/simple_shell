#include "shell.h"

char *_getenv(char *name)
{
	extern char **environ;
	char **env_var = environ;

	while(*env_var)
	{
		if (strncmp(*env_var,name, _strlen(name)) == 0 && (*env_var)[_strlen(name)] == '=')
		{
			return ((*env_var) + strlen(name) + 1);
		}
		env_var++;
	}
	return (NULL);
}
