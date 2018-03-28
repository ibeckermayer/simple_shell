#include "ss_head.h"

/**
 * gen_in_l - generate a list of inputs separated by /n or ; or &&
 * @input_list: the list to be filled in
 * @s: the input
 *
 * Return: the input_list
 */
sll **gen_in_l(sll **input_list, char *s)
{
	int i, j;
	char *cur_str = s;
	char *temp_str;

	i = j = 0;

	/* check if this is just an 'enter' */
	if (_strcmp(s, "\n") == 0)
	{
		input_list[i] = gen_sll(s, " ");
		input_list[i + 1] = NULL;
		return (input_list);
	}

	while (s[i])
	{
		if (s[i] == '\n' || s[i] == ';')
		{
			while (s[i] == '\n' || s[i] == ';')
			{
				s[i] = '\0';
				i++;
			}
			temp_str = _strdup(cur_str);
			input_list[j++] = gen_sll(temp_str, " ");
			free(temp_str);
			cur_str = s + i;
		}
		i++;
	}
	temp_str = _strdup(cur_str);
	input_list[j++] = gen_sll(temp_str, " ");
	input_list[j] = NULL;
	free(temp_str);

	return (input_list);
}


