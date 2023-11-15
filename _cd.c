#include "shell.h"
#include <unistd.h>
/**
 * _cd - changes the working directory
 * @argv: a pointer to an array of strings
 * @buffer: commands
 * @path: the path
 * Return: int
 */


int _cd(char **argv, char *buffer, char *path)
{
	char current_dir[1024];
	char *home = NULL;
	(void)path;
			if (argv[1] != NULL && strncmp("-", argv[1], 1) != 0)
			{
				if (chdir(argv[1]) != 0)
				{
					perror("chdir");
					return (-1);
				}
			}
		if (argv[1] == NULL || strncmp("-", argv[1], 1) == 0)
		{
			home = getenv("HOME");
			if (home != NULL)
				chdir(home);
		}
		if (getcwd(current_dir, sizeof(current_dir)) != NULL)
		{
			setenv("PWD", current_dir, 1);
			return (0);
		}
		else
		{
			perror("getcwd");
			return (-1);
		}
		free_token(argv, buffer, NULL);
		return (0);
}
