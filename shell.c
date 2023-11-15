#include "shell.h"
#include <stdio.h>
/**
 * main - entry point
 *
 * Return: always 0
 */

int main(void)
{
	char *path = NULL;
	char **string;

	while (1)
	{
		prompt_display();
		string = command_execute();
		path = path_handle(string);
		_execute(string, path);
		free_token(string, NULL, path);
	}
	return (0);
}
