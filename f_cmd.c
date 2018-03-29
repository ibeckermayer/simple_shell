#include "ss_head.h"

int is_path(char *command)
{
	int i = 0;

	while (command[i])
	{
		if (command[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

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

	if (is_path(command))
	{
		/* if you don't find in PATH, check absolute path */
		if (access(command, X_OK) == 0)
		{
			/* recall_path = 1; */
			return (command);
		}
	}
	/* else */
	/* { */
	/* 	perror(NULL); */
	/* } */

	/* otherwise return an empty string */
	return ("");
}
