#include "shell.h"

int main()
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
			free(user_input);
		}
	}
	return (0);
}
