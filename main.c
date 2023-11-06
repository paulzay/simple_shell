#include "shell.h"
#include <stdio.h>

int main(void)
{
	char *user_input = prompt_and_input("Enter your name: ");
	printf("hey %s", user_input);
	free(user_input);
	return (0);
}
