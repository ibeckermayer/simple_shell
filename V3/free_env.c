#include "ss_head.h"

/**
* _getenv - get environment varaible
* @name: name of variable
*
* Return: environment location
*/
void free_env()
{
	int i;

	for (i = 0; i < _BUFSIZ; i++)
		free(environ[i]);

	free(environ);
}

