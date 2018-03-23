#include "ss_head.h"
/**
 * get_error - generates sophisticated error messages
 * @prog_name: name of shell
 * @num_errors: number of errors
 * @head: head of commands linked list
 *
 * Return: error message string
 */

char *get_error(char *prog_name, int num_errors, sll *head)
{
	char *err_msg = _calloc(_BUFSIZ), *num_errors_s = _itoa(num_errors, 10),
	*spaces_1 = ": ", *spaces_2 = ":", *cmd_name = head->str;

	err_msg = _strcat(prog_name, spaces_1);
	err_msg = _strcat(err_msg, num_errors_s);
	err_msg = _strcat(err_msg, spaces_2);

	if (_strcmp(cmd_name, "cd") == 0)
	{
		err_msg = _strcat(err_msg, " ");
		err_msg = _strcat(err_msg, "cd");
		err_msg = _strcat(err_msg, spaces_2);
		err_msg = _strcat(err_msg, " can't cd to ");
		err_msg = _strcat(err_msg, head->next->str);
		err_msg = _strcat(err_msg, "\n");
	}
	else
	{
		err_msg = _strcat(err_msg, " ");
		err_msg = _strcat(err_msg, cmd_name);
		err_msg = _strcat(err_msg, spaces_2);
		err_msg = _strcat(err_msg, " not found\n");
	}

	return (err_msg);
}
