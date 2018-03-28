#include "ss_head.h"

/**
* _strcat - concatinates two strings
* @dest: string to be appende
* @src: source string to append to
* Return: th dest
*/
char *_strcat(char *dest, char *src)
{
	int size = 0, size2 = 0, j = 0, k = 0, total = 0;
	char *final;

	size = _strlen(dest);

	size2 = _strlen(src);

	final = _calloc(total = size + size2 + 1);

	while (dest[j])
	{
		final[j] = dest[j];
		j++;
	}

	for (k = 0; j < total; j++, k++)
		final[j] = src[k];

	return (final);
}
