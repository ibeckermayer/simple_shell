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
	if (!command)
		return (NULL);

	/* if you don't find in PATH, check absolute path */
	if (access(command, X_OK) == 0)
	{
		/* recall_path = 1; */
		return (command);
	}
	else
	{
		perror(NULL);
	}

	/* otherwise return an empty string */
	return ("");
}
