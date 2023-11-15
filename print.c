#include "shell.h"

/**
 * _printf - prints a string
 * @str: string to be printed
 * Return: void
 */

void _printf(char *str)
{
	write(1, str, strlen(str));
}
