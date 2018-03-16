#include "ss_head.h"

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
