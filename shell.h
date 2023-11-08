#ifndef SHELL_H
#define SHELL_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <stddef.h>

/**prompt_fn.c**/
char *read_user_input();

void printer(char *c);

/**myPrompt.c**/
void _myPrompt(void);
void end_of_file(int len, char *buff);

/**signal.c**/
void signal_handler(int sig_num);

/**shell_execution.c**/
void exec(char **argv);

#endif
