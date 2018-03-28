#include "ss_head.h"
/**
 * cut_off - helper function for cd to cut x characters
 * @to_cut: buffer to remove characters from
 * @num_to_cut: number of characters to cut
 *
 * Return: cut string
 */

char *cut_off(char *to_cut, int num_to_cut)
{
	int i = _strlen(to_cut), j = num_to_cut, k = 0;
	char *result;

	result = _calloc((i - num_to_cut) + 1);
	if (!result)
		_exit(-1);

	while (j < i)
		result[k++] = to_cut[j++];

	return (result);

}
