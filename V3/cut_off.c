#include "ss_head.h"

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
