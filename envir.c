#include "shell.h"

/**
 * envi - prints the environment variables
 * @argv: a pointer to an array of pointers to strings
 * @buffer: buffer
 * Return: void
 */

void envi(char **argv, char *buffer)
{
	int x = 0;
	(void)buffer;
	(void)argv;
		while (environ[x] != NULL)
		{
			_printf(environ[x]);
			_printf("\n");
			x++;
		}
}
