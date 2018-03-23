#include "ss_head.h"

/**
 * print_sll - prints a string linked list
 * @head: the head of the list
 *
 * Return: void
 */
void print_sll(sll *head)
{
	while (head)
	{
		printf("%s\n", head->str);
		head = head->next;
	}
}

/* !!! check for if PATH is unset */

/**
 * gen_sll - generate a string linked list given a delimeter
 * @str: the string to be searched through
 * @delim: the delimeter
 *
 * Return: the head of the sll
 */
sll *gen_sll(char *str, char *delim)
{
	char *curr_tok;

	int i, num_toks = 0;
	sll *head = NULL, *original_head = NULL, *new_node;

	if (str)
		curr_tok = _strtok(_strdup(str), delim);

	while (curr_tok != NULL)
	{
		num_toks++;
		curr_tok = _strtok(NULL, delim);
	}

	curr_tok = _strtok(str, delim);
	for (i = 0; i < num_toks; i++)
	{
		if (i == 0)
		{
			head = _calloc(sizeof(sll));
			if (!head)
				exit(-1);
			original_head = head;
		}
		head->str = _strdup(curr_tok);
		if (i < num_toks - 1)
		{
			new_node = _calloc(sizeof(sll));
			if (!new_node)
				exit(-1);
		}
		else
			new_node = NULL;
		head->next = new_node;
		head = new_node;
		curr_tok = _strtok(NULL, delim);
	}

	return (original_head);
}


