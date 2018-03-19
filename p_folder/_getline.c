#include "ss_head.h"

int _getline(int size)
{
	char *input_buffer, *realloced;
	int size_of_input = 0;

	write(1, "> ", 2);

	input_buffer = malloc(size);
	
	if (!input_buffer)
		exit(0);

	if (size == 0)
		size = 1;

	if (size_of_input = read(STDIN_FILENO, input_buffer, size) > size || size == 1)
		realloced = _realloc(input_buffer, size, size << 8);

	input_buffer[size_of_input - 1] = '\0';
	
	return (size_of_input);
}

int main(void)
{
	printf("%d\n", _getline(0));
}

/**
* _realloc - Short description, single line
* @ptr: Description of parameter size
* @old_size: Description of parameter size
* @new_size: Description of parameter size
* Return: 0
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	int old_size_i = old_size, new_size_i = new_size, i = 0;

	char *new_p;
	char *ptr_p = ptr;

	if (new_size_i == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size_i == old_size_i)
		return (ptr);

	if (ptr == NULL)
		return (malloc(sizeof(char) * new_size_i));

	new_p = malloc(sizeof(char) * new_size_i);

	if (new_p == NULL)
		return (NULL);

	while (i < new_size_i)
	{
		if (new_size_i > old_size_i)
		{

		}
		else
		{
			new_p[i] = ptr_p[i];
		}
		i++;
	}
	free(ptr);
	return (new_p);
}
