#include "shell.h"

/**
 * command - getting the user input
 * Return: the command
*/

char *command(void)
{
	char *user_input = NULL;
	size_t user_input_size = 0;

	getline(&user_input, &user_input_size, stdin);

	return (user_input);
}

/**
 * append_bin - add bin to path
 * @input: the path provided
 * Return: the new path
*/


char *append_bin(char *input)
{
	int input_len;
	char *output;

	if (strncmp(input, "/bin/", 5) == 0)
		return (input);

	input_len = strlen(input);
	output = malloc(input_len + 6);

	strcpy(output, "/bin/");
	strcat(output, input);

	return (output);
}
