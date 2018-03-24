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
	char *_paths = NULL, *full_path = NULL;
	int found = 0;
	char *_path = _getenv("PATH");
	char *_path_exp = expand_path(_path);
	recall_path = 0;

	if (!command)
		return (NULL);

	if (_path_exp)
	{
		_paths = _strtok(_strdup(_path_exp), ":");
		free(_path_exp);
		_path_exp = _paths; /* to be freed later */
	}

	/* first parse through PATH and look for it */
	while (_paths != NULL)
	{
		full_path = _strcat_slash(_paths, command);
		/* if you find it, found = 1 and break */
		if (access(full_path, F_OK) == 0)
		{
			found = 1;
			break;
		}
		free(full_path);
		_paths = _strtok(NULL, ":");
	}
	free(_path_exp);

	/* if found return the full path */
	if (found)
	{
		return (full_path);
	}


	/* if you don't find in PATH, check absolute path */
	if (access(command, F_OK) == 0)
	{
		recall_path = 1;
		return (command);
	}

	/* otherwise return an empty string */
	return ("");
}
