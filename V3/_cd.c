#include "ss_head.h"
/**
 * _cd - custom cd built-in, allows end-user to change directories
 * @head: the input line recieved
 *
 * Return: void
 */

void _cd(sll *head)
{
	char *user_dir = _getenv("HOME"),
		*prev_dir = _getenv("OLDPWD"), /* "/home/vagrant/simple_shell" */
		*err_msg,
		*name = _getenv("_=");
	char cur_dir[_BUFSIZ];
	size_t size = _BUFSIZ;
	int access_success;

	/* checks to see if global error is 0 to  start counting at 1 */
	if (!num_errors)
		num_errors++;

	if (_strcmp(head->str, "cd") == 0 && !head->next)
	{
		if (access(user_dir, F_OK) == 0)
			set_unset(user_dir);
	}
	else if (_strcmp(head->next->str, "~") == 0)
	{
		if (access(user_dir, F_OK) == 0)
			set_unset(user_dir);
	}
	else if (_strcmp(head->next->str, "-") == 0)
	{
		write(1, prev_dir, _strlen(prev_dir));
		write(1, "\n", 1);
		set_unset(prev_dir);
	}
	else if (_strcmp(head->next->str, ".") == 0)
	{
		set_unset(cur_dir);
	}
	else
	{
		getcwd(cur_dir, size);
		user_dir = _strcat_slash(cur_dir, head->next->str);
		set_unset(user_dir);

		access_success = access(user_dir, F_OK);
		printf("access_success = %d\n", access_success);

		if (access_success == 0)
		{
			/* chdir(user_dir); */

			if (chdir(user_dir) == -1)
			{
				err_msg = get_error(name + 1, num_errors, head);
				write(1, err_msg, _strlen(err_msg));
				num_errors++;
			}
		}
		else if (access_success == -1)
		{
			printf("0\n");
			err_msg = get_error(name, num_errors, head);
			printf("1\n");
			write(1, err_msg, _strlen(err_msg));
			printf("2\n");
			free(err_msg);
			printf("3\n");
			num_errors++;
			printf("4\n");
		}
		free(user_dir);
	}
}
