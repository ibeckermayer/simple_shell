#include "ss_head.h"

/**
* get_input - gets user input
*
* Return: input buffer
*/
char *get_input(void)
{
	char *input_buffer;
	int size_of_input = 0;

	input_buffer = _calloc(_BUFSIZ);
	size_of_input = read(0, input_buffer, _BUFSIZ);
	if (_strcmp(input_buffer, "") == 0)
	{
		write(1, "\n", 1);
		exit(0);
	}
	if (input_buffer[0] != '\n' && size_of_input > 0)
		input_buffer[size_of_input - 1] = '\0';
	return (input_buffer);
}
