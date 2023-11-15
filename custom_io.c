#include "shell.h"
/**
 * my_putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1. On error,
 * -1 is returned, and errno is set appropriately.
 */
int my_putchar(char c)
{
	if (write(1, &c, 1) == -1)
	{
		perror("Error writing to stdout");
		return (-1);
	}
	return (1);
}

/**
 * my_puts - Prints a string
 * @str: Pointer to string
 */

void my_puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		my_putchar(str[i]);
		i++;
	}
}
