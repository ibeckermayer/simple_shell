#include "ss_head.h"
/**
 * check_builtins - checks for builtins
 * @head: the input line recieved
 *
 * Return: either 1 or 0, 0 for success
 */

int check_builtins(sll *head)
{
	if (_strcmp(head->str, "\n") == 0)
	{
		return (0);
	}
	return (1);
}
