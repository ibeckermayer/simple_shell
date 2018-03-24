#include "ss_head.h"

/**
* check_for_his - make sure there is not history entered
* @input: input to be checked
*
* Return: 1 if found, 0 if not
*/
int check_for_his(char *input)
{
	int recal = 0, i = 0;

	while (input[i])
	{
		if (input[i++] == 'h')
			if (input[i++] == 'i')
				if (input[i++] == 's')
					if (input[i++] == 't')
						if (input[i++] == 'o')
							if (input[i++] == 'r')
								if (input[i++] == 'y')
									recal = 1;
								else
									i++;
							else
								i++;
						else
							i++;
					else
						i++;
				else
					i++;
			else
				i++;
		else
			i++;
	}

	return (recal);
}
