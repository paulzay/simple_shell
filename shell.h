#ifndef _SHELL_H
#define _SHELL_H

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
#include <limits.h>

#define BUFFER_SIZE 1024
#define MAX_PATH 4096

extern char **environ;

void _myPrompt(void);
int _strlen(char *str);
char **tokenise(char *str, char delimiter);
void exec(char **argv);
char *command(void);
int my_putchar(char c);
void my_puts(char *str);
void my_exit(char **arv);
void freearv(char **arv);
char *_which(const char *command);
char *_getenv(char *name);
void _env(void);
char *my_getline(void);
void changeDirectory(char *directory);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void end_of_file(int len, char *buff);
void signal_handler(int sig_num);
char *append_bin(char *input);

#endif /* _SHELL_H */
