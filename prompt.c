#include "shell.h"

/**
 * _isatty - checks whether the standard input is connected to a terminal 
 */

void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "myPrompt$ ", 10);
}

/**
 * _EOF - this handles the End of File
 * @len: returns the value of getline function
 * @buff: is the buffer
 */
void _EOF(int len, char *buff)
{
	(void)buff;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
			free(buff);
		}
		exit(0);
	}
}
