#include "shell.h"

/**
 * main - entry point of the program
 * Return: 0
*/

int main(void)
{
	char *user_input;
	char **tokens;

	while (1)
	{
		_myPrompt();
		user_input = my_getline();

		if (user_input != NULL)
		{
			tokens = tokenise(user_input, ' ');
			if (tokens != NULL && tokens[0] != NULL)
		{
			if (strcmp(tokens[0], "exit") == 0)
			{
				my_exit(tokens);
			}
			else if (strcmp(tokens[0], "env") == 0)
			{
				_env();
			}
			else
			{
				exec(tokens);
			}
		}
			free(tokens);
			user_input = _realloc(user_input, strlen(user_input), 0);
		}
		else
		{
			continue;
		}
	}
	return (0);
}
