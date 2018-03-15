/**
* _strcat - Short description, single line
* @dest: Description of parameter n
* @src: Description of parameter n
* Return: 0
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
