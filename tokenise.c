#include "shell.h"
/**
 * tokenise - function to tokenise
 * @str: the string
 * @delimiter: del
 * Return: tokenised char
*/
char **tokenise(char *str, char delimiter)
{
	char *token;
	char **tokens;
	int num_tokens = 0;
	char *last_char;

	tokens = (char **)malloc(sizeof(char *) * 10);
	token = strtok(str, &delimiter);
	while (token != NULL)
	{
		last_char = token + _strlen(token) - 1;
		if (*last_char == '\n')
			*last_char = '\0';
		tokens[num_tokens++] = token;
		if (num_tokens == 10)
			tokens = (char **)realloc(tokens, sizeof(char *) * (num_tokens + 10));
		token = strtok(NULL, &delimiter);
	}
	tokens[num_tokens] = NULL;
	return (tokens);
}
