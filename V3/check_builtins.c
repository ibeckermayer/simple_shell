#include "ss_head.h"
/**
 * check_builtins - checks for builtins
 * @head: the input line recieved
 *
 * Return: either 1 or 0, 0 for success
 */

int check_builtins(sll *head)
{
	/* check for cntrl-d and interative vs non-interative modes */
	if (head == NULL)
	{
		if (isatty(0))
			write(1, "\n", 1);
		_sexit();
	}
	else if (_strcmp(head->str, "exit") == 0 || _strcmp(head->str, "q") == 0)
	{
		/* !!! could pass another int to history
		 that lets it know to clear the memory */
		_sexit();
	}
	else if (_strcmp(head->str, "history") == 0 || _strcmp(head->str, "h") == 0)
	{
		_shistory(head->str, 0);
		return (0);
	}
	else if (_strcmp(head->str, "setenv") == 0)
	{
		_setenv(head->next->str, head->next->next->str, 1);
		return (0);
	}
	else if (_strcmp(head->str, "unsetenv") == 0)
	{
		_un_setenv(head->next->str);
		return (0);
	}
	else if (_strcmp(head->str, "clear") == 0)
	{
		_sclear();
		return (0);
	}
	else if (_strcmp(head->str, "env") == 0)
	{
		print_env();
		return (0);
	}
	else if (_strcmp(head->str, "\n") == 0)
	{
		return (0);
	}
	else if (_strcmp(head->str, "cd") == 0)
	{
		_cd(head);
		return (0);
	}
	else if (_strcmp(head->str, "checker") == 0)
	{
		tests();
		return (0);
	}
	return (1);
}
