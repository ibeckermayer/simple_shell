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
	char *err_msg, *num_errors_s = _itoa(num_errors, 10),
		*spaces_1 = ": ", *spaces_2 = ":", *cmd_name = head->str;
	char *temp1, *temp2;

	temp1 = _strcat(prog_name, spaces_1);
	temp2 = _strcat(temp1, num_errors_s);
	free(temp1);
	temp1 = _strcat(temp2, spaces_2);
	free(temp2);

	if (_strcmp(cmd_name, "cd") == 0)
	{
		temp2 = _strcat(temp1, " ");
		free(temp1);
		temp1 = _strcat(temp2, "cd");
		free(temp2);
		temp2 = _strcat(temp1, spaces_2);
		free(temp1);
		temp1 = _strcat(temp2, " can't cd to ");
		free(temp2);
		temp2 = _strcat(temp1, head->next->str);
		free(temp1);
		err_msg = _strcat(temp2, "\n");
		free(temp2);
	}
	else
	{
		temp2 = _strcat(temp1, " ");
		free(temp1);
		temp1 = _strcat(temp2, cmd_name);
		free(temp2);
		temp2 = _strcat(temp1, spaces_2);
		free(temp1);
		err_msg = _strcat(temp2, " not found\n");
		free(temp2);
	}

	return (err_msg);
}
