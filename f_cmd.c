#include "ss_head.h"

int is_path(char *command)
{
	int i = 0;

	while (command[i])
	{
		if (command[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

/**
* f_cmd - find shell commands PATH
* @command: commands name
*
* Return: PATH to command, NULL if no command given,
* empty string ("") if command not found
*/
char *f_cmd(char *command)
{
	int _errno = 0;

	if (!command)
		return (NULL);

	if (is_path(command))
	{
		/* if you don't find in PATH, check absolute path */
		if (access(command, F_OK) == 0)
		{
			if (access(command, X_OK) == 0)
			{
				_errno = 0;
				err_code(&_errno);
				return (command);
			}
			else
			{
				_errno = 126;
				err_code(&_errno);
			}
		}
		else
		{
			_errno = 127;
			err_code(&_errno);
		}
	}
	else
	{
		_errno = 127;
		err_code(&_errno);
	}

	/* otherwise return an empty string */
	return ("");
}
