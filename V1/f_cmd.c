#include "ss_head.h"

/**
* find_command - find shell commands PATH
* @command: commands name
* Return: PATH to command
*/

char *f_cmd(char *command, char *path)
{
	char *_path = path, *_paths = NULL, *full_path;
	int found = 0;

	_paths = strtok(_path, ":");

	while (_paths != NULL)
	{
		full_path = _strcat(_paths, command);
		if (access(full_path, F_OK) == 0)
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