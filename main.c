#include "shell.h"

void print_path_directories() {
    extern char **environ;
  char **env = environ;
  char *path = NULL;
  char *token = NULL;

  while (*env != NULL) {
    if (strncmp(*env, "PATH=", 5) == 0) {
      path = *env + 5;
      break;
    }

    env++;
  }

  if (path == NULL) {
    printf("Error: PATH environment variable not found\n");
    return;
  }

  token = strtok(path, ":");
  while (token != NULL) {
    printf("%s\n", token);
    token = strtok(NULL, ":");
  }
}
int main(int argc, char *argv[])
{
  // print_path_directories();
  while (1)
  {     
    _myPrompt();
    
    char *user_input = command();

    char **tokens = tokenise(user_input, ' ');

    exec(tokens);

    free(tokens);
    free(user_input);
  }
  return (0);
}
