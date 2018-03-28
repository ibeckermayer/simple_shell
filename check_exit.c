#include "ss_head.h"
/**
 * check_builtins - checks for builtins
 * @head: the input line recieved
 *
 * Return: either 1 or 0, 0 for success
 */

void check_exit(sll *head, sll **input_list, char *err_msg)
{
	/* check for cntrl-d and interative vs non-interative modes */
	if (head == NULL)
	{
		if (isatty(0))
			write(1, "\n", 1);
		free_sll_l(input_list);
		free(err_msg);
		_shistory(NULL, 2);
		_sexit();
	}
	else if (_strcmp(head->str, "_exit") == 0 || _strcmp(head->str, "q") == 0)
	{
		free_sll_l(input_list);
		free(err_msg);
		_shistory(NULL, 2);
		_sexit();
	}
}
