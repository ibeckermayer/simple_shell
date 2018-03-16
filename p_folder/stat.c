#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

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
}

int main(int argc, char **argv, char **environ)
{
	char *_path = find_path(environ), *_paths = NULL;

	printf("Full PATH is: %s\n", _path);

	_paths = strtok(_path, ":");

	while (_paths != NULL)
	{
		printf("%s\n", _paths);
		_paths = strtok(NULL, ":");
	}



}
