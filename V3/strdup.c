#include "ss_head.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string
 *
 * Return: Returns NULL if str = NULL, or failure
 * else returns a pointer to the copied string
 */
char *_strdup(char *str)
{
	int len, i;
	char *copy;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	copy = _calloc(len + 1);
	if (copy == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		copy[i] = str[i];
	copy[i] = '\0';

	return (copy);

}
