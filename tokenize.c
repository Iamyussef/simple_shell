#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "shell.h"
/**
 * tokenize - tokenizes the string passed
 * @str : pointer to a string to tokenize
 * Return: pointer to pointer to strings
 */
char **tokenize(char *str)
{
	size_t n = 0;
	size_t i = 0;
	char **string = NULL;
	char *token = NULL;

	if (str == NULL)
	{
		_printf("No string passed");
		return (NULL);
	}
	string = malloc(sizeof(char *) * (10 + 1));
	if (string == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	token = strtok(str, " \t\n");
	for (n = 0; token != NULL; n++)
	{
		string[n] = strdup(token);
		if (string[n] == NULL)
		{
			_printf("memory allocation failed");
			for (i = 0; i < n; i++)
				free(string[i]);
			free(string);
			return (NULL);
		}
		token = strtok(NULL, " \t\n");
	}
	string[n - 1][strlen(string[n - 1])] = '\0';
	string[n] = NULL;
	return (string);
}
