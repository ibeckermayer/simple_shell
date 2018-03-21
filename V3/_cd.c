#include "ss_head.h"
/**
 * _cd - custom cd built-in, allows end-user to change directories
 * @head: the input line recieved
 *
 * Return: void
 */

void _cd(sll *head)
{
	char *user_dir = _getenv("HOME"), *prev_dir = _getenv("OLDPWD");
	char cur_dir[_BUFSIZ];
	size_t size = _BUFSIZ;

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

		if (access(user_dir, F_OK) == 0)
		{
			chdir(user_dir);

			if (chdir(user_dir) == -1)
				perror("Error: ");
		}
		else if (access(user_dir, F_OK) == -1)
		{
			perror("Error: ");
		}
	}
}
