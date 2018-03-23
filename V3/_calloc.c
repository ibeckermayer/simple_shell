#include "ss_head.h"
/**
 * _itoa - converts int to character
 * code based on: http://www.strudel.org.uk/itoa/
 * @val: value to be converted
 * @base: base converted into
 *
 * Return: the int
 */
void *_calloc(int size)
{
	char *buf;
	int i;

	buf = malloc(size);
	if (!buf)
		return (NULL);
	for (i = 0; i < size; i++)
		buf[i] = '\0';
	/* handle_mem(buf, ADD_MEM); */
	return (buf);
}
