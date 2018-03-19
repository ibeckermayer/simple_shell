#include "ss_head.h"

/**
 * _strtok - implements similar functionality to library strtok function
 * @s: the string to be tokenized
 * @delim: the delimiter
 *
 * Return - pointer to the next token in the string
 */
char *_strtok(char *s, char *delim)
{
	static char *last_s;

	if (s == NULL)
		s = ++last_s;
	while (*s == *delim)
		s++;
	if (*s == '\0')
		return (NULL);
	if (s != NULL)
		last_s = s;
	last_s = s;
	while (*last_s != *delim && *last_s != '\0')
		last_s++;
	*last_s = '\0';
	return (s);
}
