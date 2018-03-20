#include "ss_head.h"

/**
 * _control_c - handles the CTRL-C signal
 * @sig: signal identifier
 *
 * Return: void
 */
void _control_c(int sig)
{
	UNUSED(sig);
	write(1, "\n", 1);
	show_prompt();
}
