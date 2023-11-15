#include "shell.h"
#include <stdio.h>
#include <unistd.h>
/**
 * prompt_display - displays the prompt
 * Return: void
 */
void prompt_display(void)
{
	if (isatty(STDOUT_FILENO) == 1)
	{
		_printf("#cisfun$ ");
		fflush(stdout);
	}
}
