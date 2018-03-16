#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char *find_path(char **environ)
{
	int i = 0, j = 0;

	while (environ[i])
	{
		j = 0;
		if (environ[i][j++] == 'P')
		{
			if (environ[i][j++] == 'A')
			{
				if (environ[i][j++] == 'T')
				{
					if (environ[i][j++] == 'H')
					{
						return (environ[i] + 5);
					}
				}
			}
		}
		i++;
	}
	return NULL;
}

int main(int argc, char **argv, char **environ)
{
	char *_path = find_path(environ), *_paths = NULL, *full_path;
	int i = 1;
	int fp_len;
	int found = 0;
	struct stat st;

	while (i < argc)
	{
		_paths = strtok(_path, ":");
		found = 0;
		while (_paths != NULL)
		{
			fp_len = _strlen(_paths) + strlen(argv[i]);
			full_path = malloc(fp_len);
			full_path = _strcat(full_path, argv[i]);
			if (stat(full_path, &st) == 0)
			{
				printf("%s FOUND\n", argv[i]);
				found = 1;
				break;
			}
			_paths = strtok(NULL, ":");
		}
		if (!found)
			printf("%s NOT FOUND\n", argv[i]);
		i++;
	}


	return (0);
}
