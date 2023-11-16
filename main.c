#include "shell.h"

/**
 * main - entry point of the program
 * Return: 0
*/

int main(void)
{
	char *user_input;
	ssize_t chars = 0;
	size_t size = 0;

	signal(SIGINT, signal_handler);

	while (chars != EOF)
	{
		_myPrompt();
		chars = getline(&user_input, &size, stdin);
		if (chars == -1)
		{
			perror("getline");
			break;
		}
		if (chars == 1)
		{
			continue;
		}
		char **tokens = tokenise(user_input, ' ');
		if (tokens != NULL && tokens[0] != NULL)
		{
			exec(tokens);
		}
		else
		{
			char *path = _which(tokens[0]);
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
		free(tokens);
	}
	free(user_input);
	return (0);
}
