#include "shell.h"

/**
 * print - prints a string
 * @str: string to be printed
 * Return: void
 */

void print(char *str)
{
	write(1, str, strlen(str));
}
