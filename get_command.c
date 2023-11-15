#include "shell.h"

/**
 * execute_command - a function that executes commands
 * Return: void
 */

char **execute_command(void)
{
	char *buffer = NULL, **argv = NULL;
	size_t len = 0;
	ssize_t bytes = getline(&buffer, &len, stdin);
		if (bytes == -1)
		{
			free(buffer);
			exit(0);
		}
		if (buffer[bytes] == '\n')
			buffer[bytes] = '\0';
	argv = tokenize(buffer);
		if (argv == NULL)
		{
			free_token(argv, buffer, NULL);
		}
		if (strcmp(argv[0], "cd") == 0 && argv[0] != NULL)
		{
			_cd(argv, buffer, NULL); }
		if (strcmp(argv[0], "exit") == 0 && argv[0] != NULL)
		{
			_eexit(argv, buffer); }
		if (strncmp("env", argv[0], 3) == 0)
		{
			envi(argv, buffer); }
	free_token(argv, buffer, NULL);
	return (argv);
}
/**
 * _eexit - exits the program
 * @argv: a pointer to an array of strings
 * @buffer: command
 * Return: void
 */

void _eexit(char **argv, char *buffer)
{
	int j = 0;
		if (argv != NULL)
		{
			for (j = 0; argv[j] != NULL; j++)
				free(argv[j]);
			free(argv);
		}
		if (buffer != NULL)
			free(buffer);
		exit(0);
}

/**
 * free_token - frees allocated memory
 * @argv: a pointer to an array of pointers to strings
 * @path: path
 * @buffer: buffer
 * Return: void
 */

void free_token(char **argv, char *buffer, char *path)
{
	int i = 0;
		if (argv != NULL)
		{
			for (i = 0; argv[i] != NULL; i++)
			{
				free(argv[i]);
			}
			free(argv);
		}
		if (buffer != NULL)
			free(buffer);
		if (path != NULL)
			free(path);
}
