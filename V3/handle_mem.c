#include "ss_head.h"
/**
 * _itoa - converts int to character
 * code based on: http://www.strudel.org.uk/itoa/
 * @val: value to be converted
 * @base: base converted into
 *
 * Return: the int
 */
void handle_mem(void *ptr, int mode)
{
	static pll *cur_head = NULL;
	static pll *head;
	static pll *dead_head;
	static pll *new_head;
	static pll *orig_head;

	if (!mode)
	{
		new_head = malloc(sizeof(pll));
		new_head->ptr = ptr;
		new_head->next = NULL;
		if (!cur_head)
		{
			cur_head = new_head;
			orig_head = cur_head;
		}
		else
		{
			cur_head->next = new_head;
			cur_head = new_head;
		}
	}
	else
	{
		head = orig_head;
		while (head)
		{
			free(head->ptr);
			dead_head = head;
			head = dead_head->next;
			free(dead_head);
		}
	}

}
