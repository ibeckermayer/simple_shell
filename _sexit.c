#include "ss_head.h"
/**
 * _sexit - _exits the shell
 * Return: 0 on success
 */
void _sexit(void)
{
	free_env();
	_exit(0);
}
