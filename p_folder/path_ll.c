#include "ss_head.h"

void print_pll(pll *head)
{
	while (head)
	{
		printf("%s\n", head->pdir);
		head = head->next;
	}
}

pll *path_ll()
{
	extern char **environ;
	char *_paths_o = find_path(environ), *_path = NULL;
	char *_paths = strdup(_paths_o);

	int i, num_paths = 0;
	pll *head = NULL, *original_head, *new_node;

	_path = strtok(_paths, ":");

	while (_path != NULL)
	{
		num_paths++;
		_path = strtok(NULL, ":");
	}

	_paths = _paths_o;
	_path = strtok(_paths, ":");
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
		_path = strtok(NULL, ":");
	}

	return (original_head);

}

int main(void)
{
	print_pll(path_ll());
	return (0);
}
