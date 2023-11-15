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
			handle_commands(user_input);
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
			else if (strcmp(tokens[0], "cd") == 0)
			{
				if (tokens[1] != NULL)
				{
					changeDirectory(tokens[1]);
				}
				else
				{
					changeDirectory(NULL);
				}
			}
			else
			{
				exec(tokens);
			}
		}
			free(tokens);
			free(user_input);
		}
		else
		{
			continue;
		}
	}
	return (0);
}
