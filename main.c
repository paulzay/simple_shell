#include "shell.h"

/**
 * main - entry point of the program
 * Return: 0
*/

int main(void)
{
	char *user_input;
	char **tokens;
	ssize_t chars = 0;
	char *path;
	size_t size = 0;

	signal(SIGINT, signal_handler);

	while (chars != EOF)
	{
		_myPrompt();
		chars = getline(&user_input, &size, stdin);
		end_of_file(chars, user_input);
		tokens = tokenise(user_input, ' ');
		if (tokens != NULL && tokens[0] != NULL)
		{
			exec(tokens);
		}
		else
		{
			path = _which(tokens[0]);
			if (path)
			{
				exec(tokens);
			}
			else if (!path)
			{
				free(tokens[0]);
				tokens[0] = path;
				exec(tokens);
			}
		}
	}
	free(tokens);
	free(user_input);
	return (0);
}
