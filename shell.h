// #ifndef SHELL_H
// #define SHELL_H

// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>
// #include <errno.h>
// #include <sys/wait.h>
// #include <sys/stat.h>
// #include <sys/types.h>
// #include <signal.h>
// #include <stddef.h>

// /**prompt_fn.c**/
// char *read_user_input();

// void printer(char *c);

// /**myPrompt.c**/
// void _myPrompt(void);
// void end_of_file(int len, char *buff);

// /**signal.c**/
// void signal_handler(int sig_num);

// /**shell_execution.c**/
// void exec(char **argv);

// #endif

#ifndef _SHELL_H
#define _SHELL_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>

// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>
// #include <errno.h>
// #include <sys/wait.h>
// #include <sys/stat.h>
// #include <sys/types.h>
// #include <stddef.h>


void _myPrompt(void);
int _strlen(char *str);
char **tokenise(char *str, char delimiter);
void exec(char **argv);
char *command();
int my_putchar(char c);
void my_puts(char *str);

#endif
