#include "ss_head.h"

/**
* f_cmd - find shell commands PATH
* @command: commands name
*
* Return: PATH to command, NULL if no command given,
* empty string ("") if command not found
*/
char *f_cmd(char *command)
{
	char *_paths = NULL, *full_path;
	int found = 0;
	char *_path = getenv("PATH");

	if (!command)
		return (NULL);

	_paths = _strtok(strdup(_path), ":");

	if (access(command, F_OK) == 0)
		return (command);

	while (_paths != NULL)
	{
		full_path = _strcat_slash(_paths, command);
		if (access(full_path, F_OK) == 0)
		{
			found = 1;
			break;
		}
		_paths = _strtok(NULL, ":");
	}
	if (!found)
		return ("");

	return (full_path);
}
