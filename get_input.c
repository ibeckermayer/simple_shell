#include "ss_head.h"

/**
* get_input - gets user input
*
* Return: input buffer
*/
char *get_input(void)
{
	char *input_buffer;
	size_t bufsiz = _BUFSIZ;
	int size_of_input = 0;

	input_buffer = _calloc(_BUFSIZ);
	size_of_input = getline(&input_buffer, &bufsiz, stdin);
	if (_strcmp(input_buffer, "") == 0)
	{
		if (isatty(0))
			write(1, "\n", 1);
		free(input_buffer);
		exit(0);
	}
	if (input_buffer[0] != '\n' && size_of_input > 0)
		input_buffer[size_of_input - 1] = '\0';
	return (input_buffer);
}
