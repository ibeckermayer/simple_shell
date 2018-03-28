#include "ss_head.h"
/**
 * _calloc - mallocs space and initializes to 0
 * @size: size to be malloced in bytes
 *
 * Return: pointer to allocated space
 */
void *_calloc(int size)
{
	char *buf;
	int i;

	buf = malloc(size);
	if (!buf)
	{
		perror(NULL);
		exit(-1);
	}

	for (i = 0; i < size; i++)
		buf[i] = '\0';
	return (buf);
}
