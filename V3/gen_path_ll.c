#include "ss_head.h"

void print_pll(pll *head)
{
	while (head)
	{
		printf("%s\n", head->pdir);
		head = head->next;
	}
}

/* !!! check for if PATH is unset */
pll *gen_path_ll()
{
	char *_path;
	char *_paths = getenv("PATH");

	int i, num_paths = 0;
	pll *head = NULL, *original_head, *new_node;

	_path = _strtok(_strdup(_paths), ":");

	while (_path != NULL)
	{
		num_paths++;
		_path = _strtok(NULL, ":");
	}

	_path = _strtok(_paths, ":");
	for (i = 0; i < num_paths; i++)
	{
		if (i == 0)
		{
			head = malloc(sizeof(pll));
			if (!head)
				exit(-1);
			original_head = head;
		}
		head->pdir = _strdup(_path);
		if (i < num_paths - 1)
		{
			new_node = malloc(sizeof(pll));
			if (!new_node)
				exit(-1);
		}
		else
			new_node = NULL;
		head->next = new_node;
		head = new_node;
		_path = _strtok(NULL, ":");
	}

	return (original_head);
}


