/**
* _strcat - concatinates two strings
* @dest: string to be appended
* @src: source string to append to
* Return: th dest
*/
char *_strcat(char *dest, char *src)
{
	int size = 0, size2 = 0, j, k;

	while (dest[size] != '\0')
		size++;

	while (src[size2] != '\0')
		size2++;

	for (j = size, k = 0; j < size + size2; j++, k++)
		dest[j] = src[k];

	return (dest);
}
