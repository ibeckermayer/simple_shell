/**
 * _strlen - get size of string
 * @s: string to get size of
 * Return: size of string
 */

int _strlen(const char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
