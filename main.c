#include "shell.h"

int main(int argc, char *argv[])
{
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
