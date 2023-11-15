#include "shell.h"

/**
 * execute_command - a function that executes commands
 * Return: void
 */

char **command_execute(void)
{
	char *buffer = NULL, **strings = NULL;
	size_t length = 0;
	ssize_t bytes = getline(&buffer, &length, stdin);
		if (bytes == -1)
		{
			free(buffer);
			exit(0);
		}
		if (buffer[bytes] == '\n')
			buffer[bytes] = '\0';
	strings = tokenize(buffer);
		if (strings == NULL)
		{
			free_token(strings, buffer, NULL);
		}
		if (strcmp(strings[0], "cd") == 0 && strings[0] != NULL)
		{
			_cd(strings, buffer, NULL); }
		if (strcmp(strings[0], "exit") == 0 && strings[0] != NULL)
		{
			_eexit(strings, buffer); }
		if (strncmp("env", strings[0], 3) == 0)
		{
			envi(strings, buffer); }
	free_token(NULL, buffer, NULL);
	return (strings);
}
/**
 * _eexit - successfully exits the program
 * @argv: a pointer to pointer strings
 * @buffer: command string
 * Return: void
 */

void _eexit(char **string, char *buffer)
{
	int n = 0;
	if (string != NULL)
	{
		for (n = 0; string[n] != NULL; n++)
			free(string[n]);
		free(string);
	}
	if (buffer != NULL)
		free(buffer);
	exit(0);
}

/**
 * free_token - frees the allocated memory
 * @argv: a pointer to pointer to strings
 * @path: path string
 * @buffer: buffer
 * Return: nothing
 */

void free_token(char **string, char *buffer, char *path)
{
	int n = 0;

	if (string != NULL)
	{
		for (n = 0; string[n] != NULL; n++)
		{
			free(string[n]);
		}
		free(string);
	}
	if (buffer != NULL)
		free(buffer);
	if (path != NULL)
		free(path);
}
