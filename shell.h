#ifndef _SHELL_H
#define _SHELL_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <stddef.h>
#include <signal.h>
#include <sys/stat.h>

void _myPrompt(void);
int _strlen(char *str);
char **tokenise(char *str, char delimiter);
void exec(char **argv);
char *command();
int my_putchar(char c);
void my_puts(char *str);
void my_exit(char **arv);

#endif
