#include "shell.h"
/**
 * changeDirectory - Change the current working directory of the process.
 * @directory: The target directory to change to.
 *
 * Return: void
 */

void changeDirectory(char *directory)
{
	char newDir[MAX_PATH];
	char oldDir[MAX_PATH];

	const char *homeDir = getenv("HOME");
	const char *previousDir = getenv("OLDPWD");

	if (!directory || !strlen(directory))
	{
		if (!homeDir)
		{
			fprintf(stderr, "cd: HOME not set\n");
			return;
		}
		strcpy(newDir, homeDir);
	} else if (strcmp(directory, "-") == 0)
	{
		if (!previousDir)
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
			return;
		}
		strcpy(newDir, previousDir);
	} else
	{
		strcpy(newDir, directory);
	}
	if (!getcwd(oldDir, sizeof(oldDir)))
	{
		perror("getcwd");
		return;
	}
	if (chdir(newDir) != 0)
	{
		perror("chdir");
		return;
	}
	if (setenv("PWD", newDir, 1) != 0 || setenv("OLDPWD", oldDir, 1) != 0)
	{
		perror("setenv");
	}
}
