#include "ss_head.h"

/**
* _getenv - get environment varaible
* @name: name of variable
*
* Return: environment location
*/
void extract_env()
{
	char **new_environ;
	int i;

	new_environ = _calloc(_BUFSIZ * sizeof(char **));

	for (i = 0; environ[i]; i++)
		new_environ[i] = _strdup(environ[i]);

	environ = new_environ;
}

