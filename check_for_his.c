#include "ss_head.h"

/**
* check_for_his - make sure there is not history entered
* @input: input to be checked
* @tocheck: string to look for
*
* Return: 1 if found, 0 if not
*/
int check_for_his(char *input, char *tocheck)
{
	int recal = 2, i = 0, j = 0, k = 0, size = _strlen(tocheck);

	if (size == 1)
		if (input[0] == tocheck[0])
			return (1);

	while (input[k])
	{
		i = k;
		if (input[i] == tocheck[j])
		{
			while (j < size)
			{
				if (input[i] == tocheck[j])
				{
					if (size == 1)
						if (input[--i] || input[i++])
						{
							recal = 0;
							break;
						}

					recal = 1;
					i++;
					j++;
				}
				else
				{
					recal = 0;
					break;
				}
			}
		}
		if (size == j || recal == 0)
			break;
		else
			k++;
	}
	if (recal == 2)
		recal = 0;
	
	return (recal);
}
