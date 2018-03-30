#include "ss_head.h"
/**
 * _sclear - clear the screen
 * Return: void
 */
void _sclear(void)
{
	const char *CLEAR_SCREEN_ANSI = "\x1B[1;1H\x1B[2J";

	write(1, CLEAR_SCREEN_ANSI, 11);
}
