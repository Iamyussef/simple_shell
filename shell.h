#ifndef SHELL_H
#define SHELL_H

/*************-libraries-************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stddef.h>
#include <limits.h>
#include <string.h>

extern char **environ;

void _printf(char *str);
void prompt_display(void);
void envi(char **argv, char *buffer);
int _execute(char **argv, char *path);
char *path_handle(char **argv);
int _cd(char **argv, char *buffer, char *path);
void free_token(char **string, char *buffer, char *path);
void _eexit(char **string, char *buffer);
char **tokenize(char *str);
char **command_execute(void);

#endif
