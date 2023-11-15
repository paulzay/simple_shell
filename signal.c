#include "shell.h"

/**
 * signal_handler - handles the SIGINT signal (Ctrl+C)
 * @sig_num: the signal number to be handled
 */
void signal_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		write(STDOUT_FILENO, "$ ", strlen(" "));
	}
}
