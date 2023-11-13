#include "shell.h"

/**
 * exec - this executes a command
 * @argv: is an array of arguments
 */

void exec(char **argv)
{
	int child_id;
  char *executable;
  /*
  char *path = _getenv(argv[0]);

  char *envp[] = {path, NULL};
  */
	if (argv[0] && strlen(argv[0]) < 2) {
		return;
	}

  executable = _which(argv[0]);
  if (executable != NULL)
  {
    child_id = fork();

    if (child_id == 0)
    {
      /* char *args[] = { argv[0], NULL }; */
      execve(executable, argv, NULL);
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
