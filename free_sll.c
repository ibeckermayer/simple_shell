#include "ss_head.h"

/**
 * free_sll - free's a string linked list
 * @head: head of the list
 *
 * Return: void
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


