#include "ss_head.h"

/**
* _setenv - set environment varaible
* @name: name of variable
*
* Return: void
*/
void _setenv(char *name, char *value)
{
	char *cur_val = _getenv(name);
	int i;

	if (cur_val)
	{
		cur_val -= _strlen(name) + 1;
		_strcpy(cur_val, _strcat(_strcat(name, "="), value));
	}
	else
	{
		/* scan through entire environ var */
		i = 0;
		while (environ[i])
			i++;
		environ[i++] = _strcat(_strcat(name, "="), value);
		environ[i] = NULL;
	}

}
