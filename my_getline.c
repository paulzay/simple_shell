#include "shell.h"
#define BUFFER_SIZE 1024

char *my_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static int index = 0;
	static int bytesRead = 0;
	char *line = NULL;
	int lineIndex = 0;
	char currentChar;

	while (1)
	{
		if (index == bytesRead)
		{
			bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (bytesRead <= 0)
			{
				break;
			}
			index = 0;
		}
		currentChar = buffer[index++];
		if (lineIndex % BUFFER_SIZE == 0)
		{
			char *temp = realloc(line, lineIndex + BUFFER_SIZE);
			if (temp == NULL)
			{
				free(line);
				return NULL;
			}
			line = temp;
		}
		line[lineIndex++] = currentChar;
		if (currentChar == '\n')
		{
			line[lineIndex - 1] = '\0';
			return line;
		}
	}
	if (line != NULL)
	{
		free(line);
	}
	return NULL;
}
