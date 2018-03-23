#include "ss_head.h"

/**
 * gen_ldkslfjds - generate an array of linked list pointers
 * @str: the string to be searched through
 * @delim: the delimeter
 *
 * Return: the head of the sll
 */
sll **gen_in_l(sll **input_list, char *s)
{
	int i, j;
	char *cur_str = s;
	char *temp_str;
	int inp_len = _strlen(s);

	i = j = 0;

	/* check if this is just an 'enter' */
	if (_strcmp(s, "\n") == 0)
	{
		input_list[i] = gen_sll(s, " ");
		input_list[i+1] = NULL;
		return (input_list);
	}


	while(s[i])
	{
		if (s[i] == '\n' || s[i] == ';')
		{
			/* !!! ; behavior should be different than \n */
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
		/* !!! edgecase where && is at the very end */
		else if (s[i] == '&')
		{
			if (i < inp_len - 1)
				if (s[i + 1] == '&')
				{
					s[i] = '\0';
					s[i + 1] = '\0';
					i += 2;
					temp_str = _strdup(cur_str);
					input_list[j++] = gen_sll(temp_str, " ");
					free(temp_str);
					cur_str = s + i;
				}
				else
					i++;
			else
				i++;
		}
		else
			i++;
	}
	temp_str = _strdup(cur_str);
	input_list[j++] = gen_sll(temp_str, " ");
	input_list[j] = NULL;
	free(temp_str);

	return (input_list);
}


