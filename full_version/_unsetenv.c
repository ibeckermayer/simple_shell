#include "ss_head.h"

/**
* _setenv - set environment varaible
* @name: name of variable
* @value: value to set
*
* Return: void
*/
void _un_setenv(char *name)
{
	char *cur_val = _getenv(name), *temp1, *full_name;
	int environ_len, name_loc, i;

	if (!cur_val)
	{
		/* !!! error message */
	}
	else
	{
		temp1 = _strcat(name, "=");
		full_name = _strcat(temp1, cur_val);
		free(temp1);

		/* scan through entire environ var, finding length and loc of name */
		environ_len = name_loc = 0;
		while (environ[environ_len])
		{
			if (_strcmp(environ[environ_len], full_name) == 0)
			{
				name_loc = environ_len;
			}
			environ_len++;
		}
		free(full_name);

		for (i = name_loc; i < environ_len - 1; i++)
		{
			environ[i] = environ[i + 1];
		}

		environ[environ_len - 1] = NULL;
	}
}
