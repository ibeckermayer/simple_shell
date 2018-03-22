#include "ss_head.h"

/**
 * _strdup - expands the path to add current dir for :: or : at the beginning
 * which contains a copy of the string given as a parameter.
 * @str: string
 *
 * Return: Returns NULL if str = NULL, or failure
 * else returns a pointer to the copied string
 */
char *expand_path(char *path)
{
	int i, j, tot_len, num_exp = 0;
	char *expndd;

	if (path == NULL)
		return (NULL);

	i = 0;
	while(path[i])
	{
		if (i == 0 && path[i] == ':')
		{
			num_exp++;
			i++;
		}
		else if (path[i] == ':')
		{
			if (path[i + 1] == ':')
			{
				num_exp++;
				i += 2;
			}
			else
				i++;
		}
		else
			i++;
	}

	tot_len = _strlen(_getenv("PWD")) * num_exp + _strlen(path);
	expndd = malloc(tot_len);

	i = j = 0;
	while (i < tot_len)
	{
		if (j == 0 && path[j] == ':')
		{
			expndd[0] = '\0'; /* for _strcat */
			_strcat(expndd, _getenv("PWD"));
			i += _strlen(_getenv("PWD"));
			expndd[i] = '\0'; /* for _strcat */
			_strcat(expndd, path);
			j++;
		}
		else if (path[j] == ':' && path[j + 1] == ':')
		{
			expndd[i] = '\0';
			_strcat(expndd, _getenv("PWD"));
			i += _strlen(_getenv("PWD"));
			expndd[i] = '\0'; /* for _strcat */
			_strcat(expndd, path + j + 1);
			j += 2;
		}
		else
		{
			expndd[i++] = path[j++];
		}
	}

	return(expndd);

}
