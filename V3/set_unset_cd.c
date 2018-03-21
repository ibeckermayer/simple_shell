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

	prev_dir = malloc(size);
	cur_dir = malloc(size);

	getcwd(prev_dir, size);
	chdir(dir);
	getcwd(cur_dir, size);
	_setenv("OLDPWD", prev_dir);
	_setenv("PWD", cur_dir);
}
