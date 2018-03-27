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
	if (input_buffer == NULL)
		exit(0);
	size_of_input = read(0, input_buffer, _BUFSIZ);
	if (input_buffer[0] != '\n' && size_of_input > 0)
		input_buffer[size_of_input - 1] = '\0';
	return (input_buffer);
}
