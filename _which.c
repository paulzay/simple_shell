#include "shell.h"

char *_which(const char *command) {
  char *path = _getenv("PATH");
  char *delim = ":";
  char *token = strtok(path, delim);
  char *full_path = NULL;

  while (token != NULL) {
    full_path = (char *)malloc(strlen(token) + strlen(command) + 2);
    sprintf(full_path, "%s/%s", token, command);

    if (access(full_path, F_OK) == 0) {
      return full_path;
    }

    free(full_path);
    token = strtok(NULL, delim);
  }

  return NULL;
}
