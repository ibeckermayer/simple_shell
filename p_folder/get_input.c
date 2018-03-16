#include "ss_head.h"

char *getinput(void)
{
	char *input_buffer;
	int size_of_input = 0, buffer_size = 10, i = 0;

	input_buffer = malloc(1 << 10);

	write(1, "$ ", 2);

	while (size_of_input = read(0, input_buffer, 1 << buffer_size) > 1 << buffer_size)
	{
		buffer_size *= 10;
		size_of_input = read(0, input_buffer, 1 << buffer_size);
	}

	return (input_buffer);
}

int main(void)
{
	char *to_print = getinput(), *result;
	result = _strcat("This is a test from main: ", to_print);
	write(1, result, _strlen(to_print) + 32);
	return (0);
}