#include "ss_head.h"
/**
 * check_builtins - checks for builtins
 * @input: the input line recieved
 *
 * Return: either 1 or 0, 0 for success
 */

int check_builtins(char *input)
{
	if (_strcmp(input, "history") == 0 || _strcmp(input, "h") == 0)
	{
		_shistory(input, 0);
		return (0);
	}
	else if (_strcmp(input, "setenv") == 0)
	{
		_setenv("NEWVAR", "NEWVAL!");
		return (0);
	}
	else if (_strcmp(input, "clear") == 0)
	{
		_sclear();
		return (0);
	}
	else if (_strcmp(input, "exit") == 0 ||
		 _strcmp(input, "quit") == 0 ||
		 _strcmp(input, "") == 0)
	{
		write(1, "\n", 1);
		_sexit();
	}
	else if (_strcmp(input, "env") == 0)
	{
		print_env();
		return (0);
	}
	else if (_strcmp(input, "\n") == 0)
	{
		return (0);
	}
	return (1);
}
