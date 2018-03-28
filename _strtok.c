#include "ss_head.h"

/**
 * _strtok - implements similar functionality to library _strtok function
 * @s: the string to be tokenized
 * @delim: the delimiter
 *
 * Return: pointer to the next token in the string
 */
char *_strtok(char *s, char *delim)
{
	static char *last_s;
	static int size;
	static char *orig_s;

	if (s)
	{
		size = _strlen(s);
		orig_s = s;
	}

	if (s == NULL)
	{
		if (++last_s - orig_s < size)
			s = last_s;
		else
		{
			/* if (orig_s) */
				/* free(orig_s); */
			return (NULL);
		}
	}
	while (*s == *delim)
		s++;
	if (*s == '\0')
	{
		return (NULL);
		/* free(orig_s); */
	}
	if (s != NULL)
		last_s = s;
	last_s = s;
	while (*last_s != *delim && *last_s != '\0')
		last_s++;
	*last_s = '\0';
	return (s);
}
