#include "shell.h"

/**
 * exec - this executes a command
 * @argv: is an array of arguments
 */

void exec(char **argv)
{
	int child_id;
  char *envp[] = {_getenv(argv[0]), NULL};

	if (argv[0] && strlen(argv[0]) < 2) {
		return;
	}

  char *executable = _which(argv[0]);
  if (executable == NULL)
     printf("Executable not found: ls\n");
   else
   {
      child_id = fork();

      if (child_id == 0)
      {
        // char *args[] = { argv[0], NULL };
        execve(executable, argv, envp);
        perror(argv[0]);
        exit(1);
      }
      else if (child_id > 0)
      {
        waitpid(child_id, NULL, 0);
      }
      else
      {
        perror("fork failed");
        exit(1);
      }
  }
}
