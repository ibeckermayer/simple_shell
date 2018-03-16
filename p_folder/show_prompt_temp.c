#include "ss_head.h"

/**
* show_prompt - shows prompt
* @buffer: buffer to store
* Return: user input
*/

char *show_prompt(char *buffer)
{
	int i = 0;
	buffer = get_input();

	while (buffer[i] != '\n')
		i++;

	buffer[i] = 0;

	return (buffer);

}