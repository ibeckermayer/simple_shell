#include "ss_head.h"

/**
 * gen_ldkslfjds - generate an array of linked list pointers
 * @str: the string to be searched through
 * @delim: the delimeter
 *
 * Return: the head of the sll
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


