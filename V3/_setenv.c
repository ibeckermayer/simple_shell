#include "ss_head.h"

/**
* _setenv - set environment varaible
* @name: name of variable
* @value: value to set
*
* Return: void
*/
void _setenv(char *name, char *value)
{
	char *cur_val = _getenv(name);
	char *temp1, *temp2;
	int i;

	if (cur_val)
	{
		cur_val -= _strlen(name) + 1;
		temp1 = _strcat(name, "=");
		temp2 = _strcat(temp1, value);
		_strcpy(cur_val, temp2);
		free(temp1);
		free(temp2);
	}
	else
	{
		/* scan through entire environ var */
		i = 0;
		while (environ[i])
			i++;
		temp1 = _strcat(name, "=");
		temp2 = _strcat(temp1, value);
		/* !!! test this!!! */
		_strcpy(environ[i++], temp2);
		environ[i] = NULL;
		free(temp1);
		free(temp2);
	}

}
