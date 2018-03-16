#include "ss_head.h"

/**
* find_command - find shell commands PATH
* @command: commands name
* Return: PATH to command
*/

char *find_command(char *command)
{
	extern char **environ;
	char *_path = find_path(environ), *_paths = NULL, *full_path;
	int i = 1, found = 0;
	struct stat st;

	_paths = strtok(_path, ":");

	while (_paths != NULL)
	{
		full_path = _strcat(_paths, command);
		if (stat(full_path, &st) == 0)
		{
			found = 1;
			break;
		}
		_paths = strtok(NULL, ":");
	}
	if (!found)
		printf("%s NOT FOUND\n", command);

	return(full_path);
}
