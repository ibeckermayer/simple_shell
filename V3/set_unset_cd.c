#include "ss_head.h"
/**
 * set_unset - set env variables
 * @dir: dir to change to
 *
 * Return: void
 */

void set_unset(char *dir)
{
	char *prev_dir, *cur_dir;
	int size = _BUFSIZ;

	prev_dir = _calloc(size);
	cur_dir = _calloc(size);

	/* !!! should only set env variables if chdir works properly */
	getcwd(prev_dir, size);
	chdir(dir);
	getcwd(cur_dir, size);
	_setenv("OLDPWD", prev_dir);
	_setenv("PWD", cur_dir);
	free(prev_dir);
	free(cur_dir);
}
