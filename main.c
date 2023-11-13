#include "shell.h"

int main()
{
  char *user_input;
  char **tokens;
  while (1)
  {     
    _myPrompt();
    
    user_input = command();

    tokens = tokenise(user_input, ' ');

    exec(tokens);

    free(tokens);
    free(user_input);
  }
  return (0);
}
