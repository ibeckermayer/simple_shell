#include "ss_head.h"
/**
 * check_builtins - checks for builtins
 * @input: the input line recieved
 *
 * Return: either 1 or 0, 0 for success
 */

int check_builtins(sll *head)
{

	if (_strcmp(head->str, "history") == 0 || _strcmp(head->str, "h") == 0)
	{
		while (head)
		{
			_shistory(head->str, 0);
			head = head->next;
		}
		return (0);
	}
	else if (_strcmp(head->str, "clear") == 0)
	{
		_sclear();
		return (0);
	}
	else if (_strcmp(head->str, "exit") == 0 ||
		 _strcmp(head->str, "quit") == 0 ||
		 _strcmp(head->str, "") == 0)
	{
		write(1, "\n", 1);
		_sexit();
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
	return (1);
}
