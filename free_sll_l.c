#include "ss_head.h"

/**
 * free_sll_l - free's an array of string linked lists
 * @input_list: the list
 *
 * Return: void
 */
void free_sll_l(sll **input_list)
{
	int i = 0;

	while (input_list[i])
	{
		free_sll(input_list[i++]);
	}
	free(input_list);
}


