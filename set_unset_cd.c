#include "ss_head.h"
/**
 * set_unset - set env variables
 * @dir: dir to change to
 *
 * Return: 0 on success, 1 on failure
 */

int set_unset(char *dir)
{
	char *prev_dir, *cur_dir;
	int size = _BUFSIZ;
	int success;

	prev_dir = _calloc(size);
	cur_dir = _calloc(size);

	/* !!! should only set env variables if chdir works properly */
	getcwd(prev_dir, size);
	if (chdir(dir) == 0)
	{
		success = 0;
		getcwd(cur_dir, size);
		_setenv("OLDPWD", prev_dir, 1);
		_setenv("PWD", cur_dir, 1);
	}
	else
		success = 1;

	free(prev_dir);
	free(cur_dir);

	return (success);
}
