#include "shell.h"

void changeDirectory(char *directory)
{
	char newDir[MAX_PATH];

	if (directory == NULL || strlen(directory) == 0)
	{
		const char *homeDir = getenv("HOME");

		if (homeDir == NULL)
		{
			fprintf(stderr, "cd: HOME not set\n");
			return;
		}
		strcpy(newDir, homeDir);
	}
	else if (strcmp(directory, "-") == 0)
	{
		const char *previousDir = getenv("OLDPWD");

		if (previousDir == NULL)
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
			return;
		}
		strcpy(newDir, previousDir);
	}
	else
	{
		strcpy(newDir, directory);
	}
	char oldDir[MAX_PATH];

	if (getcwd(oldDir, sizeof(oldDir)) == NULL)
	{
		perror("getcwd");
		return;
	}
	if (chdir(newDir) != 0)
	{
		perror("chdir");
		return;
	}
	if (setenv("PWD", newDir, 1) != 0)
	{
		perror("setenv");
		return;
	}
	if (setenv("OLDPWD", oldDir, 1) != 0)
	{
		perror("setenv");
		return;
	}
}
// else if (strcmp(tokens[0], "cd") == 0)
// {
// 	if (tokens[1] != NULL)
// 	{
// 		changeDirectory(tokens[1]);
// 	}
// 	else
// 	{
// 		changeDirectory(NULL);
// 	}
// }