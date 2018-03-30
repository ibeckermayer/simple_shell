#include "ss_head.h"
/**
 * print_env - prints all evn variables
 * Return: void
 */
void print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		write(1, environ[i], _strlen(environ[i]));
		i++;
		write(1, "\n", 1);
	}
}
