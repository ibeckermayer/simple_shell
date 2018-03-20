#include "ss_head.h"
/**
 * cut_off - helper function for cd which removed cd from input
 * @to_cut: buffer to remove characters from
 * @num_to_cut: number of characters to cut from front
 *
 * Return: cut string
 */

char *cut_off(char *to_cut, int num_to_cut)
{
	int i = 0, j = num_to_cut, k = 0;
	char *result;

	while (to_cut[i++])
		;

	result = malloc(i * sizeof(char));
	if (!result)
		printf("error\n");

	while (j < i)
		result[k++] = to_cut[j++];

	return (result);

}
