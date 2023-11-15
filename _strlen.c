#include "shell.h"

/**
 * _strlen - function to get length of string
 * @str: the string
 * Return: length of string
*/

int _strlen(char *str)
{
	int count;

	for (count = 0; *str != '\0'; str++)
	{
		count++;
	}

	return (count);
}
