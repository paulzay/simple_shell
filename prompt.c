#include "shell.h"

/**
 * _isatty - checks whether the standard input is connected to a terminal 
 */

void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("myPrompt$ ");
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
			_puts("\n");
			free(buff);
		}
		exit(0);
	}
}
