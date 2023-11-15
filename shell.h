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

void print(char *str);
void prompt(void);
void envi(char **argv, char *buffer);
int execute(char **argv, char *path);
char *_path(char **argv);
int _cd(char **argv, char *buffer, char *path);
void free_token(char **argv, char *buffer, char *path);
void _eexit(char **argv, char *buffer);
char **tokenize(char *str);
char **execute_command(void);

#endif