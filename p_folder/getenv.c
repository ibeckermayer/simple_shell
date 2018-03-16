#include "ss_head.h"

/**
* _getenv - get environment varaible
* @name: name of variable
* Return: environment location
*/

char *_getenv(const char *name)
{
	extern char **environ;
	int len = _strlen(name);
	int i = 0;
	int j;


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
			return (environ[i] + len + 1);
		i++;
	}
	return NULL;
}
