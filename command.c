#include "shell.h"

/**
 * command - getting the user input
 * Return: the command
*/

char *command()
{
	char *user_input = NULL;
	size_t user_input_size = 0;

	getline(&user_input, &user_input_size, stdin);

	return (user_input);
}
