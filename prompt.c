#include "shell.h"

/**
 * _myPrompt - checks whether the standard input is connected to a terminal 
 */

void _myPrompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 3);
}

/**
 * end_of_file - this handles the End of File
 * @len: returns the value of getline function
 * @buff: is the buffer
 */
void end_of_file(int len, char *buff)
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
