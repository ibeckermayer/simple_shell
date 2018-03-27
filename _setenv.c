#include "ss_head.h"

/**
* _setenv - set environment varaible
* @name: name of variable
* @value: value to set
*
* Return: void
*/
void _setenv(char *name, char *value, int d)
{
	char *cur_val = getenv(name);
	char *temp1, *temp2, *to_be_freed;
	int i, j, len;
	len = _strlen(name);
	UNUSED(d);

	if (cur_val)
	{
		i = 0;
		while (environ[i])
		{
			for (j = 0; j < len; j++)
			{
				if (name[j] == environ[i][j])
					;
				else
					break;
			}
			if (j == len)
				break;
			i++;
		}

		to_be_freed = environ[i];
		temp1 = _strcat(name, "=");
		temp2 = _strcat(temp1, value);
		environ[i] = temp2;
		free(temp1);
		free(to_be_freed);
	}
	else
	{
		/* scan through entire environ var */
		i = 0;
		while (environ[i])
			i++;
		temp1 = _strcat(name, "=");
		temp2 = _strcat(temp1, value);
		environ[i++] = _strdup(temp2);
		environ[i] = NULL;
		free(temp1);
		free(temp2);
	}

}
