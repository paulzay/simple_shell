#include <stdio.h>

char *prompt_and_input(const char *prompt)
{
	char *user_input = NULL;
	size_t user_input_size = 0;

	printf("%s", prompt);
	fflush(stdout);


	getline(&user_input, &user_input_size, stdin);

	if (user_input[user_input_size - 1] == '\n)
		user_input[user_input_size - 1] = '\0';

	return (user_input);
}
