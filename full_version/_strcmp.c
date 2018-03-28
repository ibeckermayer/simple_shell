/**
 * _strcmp - compares the strings
 * @s1: string
 * @s2: string
 *
 * Return: difference between first non-equal char
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
