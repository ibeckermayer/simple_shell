#include "ss_head.h"

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
	char *dup;
	int i, num_toks = 0;
	sll *head = NULL, *original_head = NULL, *new_node;

	if (str)
	{
		dup = _strdup(str);
		curr_tok = _strtok(dup, delim);
	}
	while (curr_tok != NULL)
	{
		num_toks++;
		curr_tok = _strtok(NULL, delim);
	}
	free(dup);
	curr_tok = _strtok(str, delim);
	for (i = 0; i < num_toks; i++)
	{
		if (i == 0)
		{
			head = _calloc(sizeof(sll));
			original_head = head;
		}
		if (i < num_toks - 1)
		{
			new_node = _calloc(sizeof(sll));
			if (!new_node)
				_exit(-1);
		}
		else
			new_node = NULL;
		head->str = _strdup(curr_tok);
		head->next = new_node;
		head = new_node;
		curr_tok = _strtok(NULL, delim);
	}
	return (original_head);
}


