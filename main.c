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
			if (strcmp(tokens[0], "exit") == 0)
			{
				my_exit(tokens);
			} else
			{
				exec(tokens);
			}
		} else
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
	freearv(tokens);
	free(user_input);
	return (0);
}
