#include "ss_head.h"

/**
 * gen_ldkslfjds - generate an array of linked list pointers
 * @str: the string to be searched through
 * @delim: the delimeter
 *
 * Return: the head of the sll
 */
void free_sll(sll *head)
{
	sll *head2;

	while (head)
	{
		head2 = head->next;
		free(head->str);
		free(head);
		head = head2;
	}
}


