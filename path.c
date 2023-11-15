#include "shell.h"
/**
 * path_handle - a function that handles the path
 * @argv: pointer to array of string
 * Return: returns a pointer to the executable command
 */
char *path_handle(char **argv)
{
	char *_path = getenv("PATH");
	char *path_du = strdup(_path);
	char *token = strtok(path_du, ":");

	if (path_du == NULL)
	{
		return (NULL);
	}
	while (token != NULL)
	{
		size_t argv_length = strlen(argv[0]);
		size_t token_length = strlen(token);
		size_t command_length = token_length + 1 + argv_length + 1;
		char *command = malloc(command_length);

		if (command != NULL)
		{
			strcpy(command, token);
			command[token_length] = '/';
			strcpy(command + token_length + 1, argv[0]);
		}
		if (access(command, X_OK) == 0)
		{
			free(path_du);
			return (command);
		}
		free(command);
		token = strtok(NULL, ":");
	}
	free(path_du);
	return (NULL);
}
/**
 * _execute - executes commands
 * @argv: pointer to pointer to strings
 * @path: pointer to path
 * Return: void
 */
int _execute(char **argv, char *path)
{
	int _status = 0;
	pid_t child;

	if (path == NULL)
	{
		path = argv[0];
	}
	if (access(path, F_OK) == 0)
	{
		child = fork();
		if (child == -1)
		{
			perror("fork");
			return (errno);
		}
		else if (child == 0)
		{
			if (execve(path, argv, NULL) == -1)
			{
				perror(path);
				return (errno);
			}
		}
		else
		{
			wait(&_status);
			return (WEXITSTATUS(_status));
		}
	}
	perror("./shell");
	return (errno);
}
