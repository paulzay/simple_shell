#include "shell.h"

/**
 * main - is the entry point for execution.
 * Return: 0 on success
 */

int main(void)
{
	char *user_input = prompt_and_input("Enter your name: ");
	if (user_input != NULL)
	{
		write(STDOUT_FILENO, "hey ", 4);
		write(STDOUT_FILENO, user_input, strlen(user_input));
		free(user_input);
	}
	signal(SIGINT, signal_handler);
	  while (1)
	  {
		  if (isatty(fileno(stdin)))
		  {
			  write(STDOUT_FILENO, "#myPrompt$ ", 11);
		  }
		  if (getline(&buff, &size, stdin) == -1)
		  {
			  perror("getline");
			  break;
		  }
		  end_of_file(len, buff);
		  free(buff);
	  }
	  return (0);
}
