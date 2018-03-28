#include "ss_head.h"

int check_input_syntax(char *s, char *prog_name)
{
	char *err_msg, *num_errors_s = _itoa(num_errors, 10),
		*spaces_1 = ": ";
	char *temp1, *temp2;
	int i, len;

	while (*s == '\n' || *s == ' ')
		s++;

	/* check for ; or ;; start */
	if (*s == ';')
	{
		s++;
		if (*s == ';')
		{
			temp1 =  _strcat(prog_name, spaces_1);
			temp2 = _strcat(temp1, num_errors_s);
			free(temp1);
			temp1 = _strcat(temp2, spaces_1);
			free(temp2);
			err_msg = _strcat(temp1, "Syntax error: \";;\" unexpected\n");
			free(temp1);
			write(2, err_msg, _strlen(err_msg));
			free(err_msg);
			return (1);
		}
		else
		{
			temp1 =  _strcat(prog_name, spaces_1);
			temp2 = _strcat(temp1, num_errors_s);
			free(temp1);
			temp1 = _strcat(temp2, spaces_1);
			free(temp2);
			err_msg = _strcat(temp1, "Syntax error: \";\" unexpected\n");
			free(temp1);
			write(2, err_msg, _strlen(err_msg));
			free(err_msg);
			return (1);
		}
	}

	/* check for & or && start */
	if (*s == '&')
	{
		s++;
		if (*s == '&')
		{
			temp1 =  _strcat(prog_name, spaces_1);
			temp2 = _strcat(temp1, num_errors_s);
			free(temp1);
			temp1 = _strcat(temp2, spaces_1);
			free(temp2);
			err_msg = _strcat(temp1, "Syntax error: \"&&\" unexpected\n");
			free(temp1);
			write(2, err_msg, _strlen(err_msg));
			free(err_msg);
			return (1);
		}
		else
		{
			temp1 =  _strcat(prog_name, spaces_1);
			temp2 = _strcat(temp1, num_errors_s);
			free(temp1);
			temp1 = _strcat(temp2, spaces_1);
			free(temp2);
			err_msg = _strcat(temp1, "Syntax error: \"&\" unexpected\n");
			free(temp1);
			write(2, err_msg, _strlen(err_msg));
			free(err_msg);
			return (1);
		}
	}

	/* check for any ;; */
	len = _strlen(s);
	for (i = 0; i < len - 1; i++)
	{
		if (s[i] == ';' && s[i + 1] == ';')
		{
			temp1 =  _strcat(prog_name, spaces_1);
			temp2 = _strcat(temp1, num_errors_s);
			free(temp1);
			temp1 = _strcat(temp2, spaces_1);
			free(temp2);
			err_msg = _strcat(temp1, "Syntax error: \";;\" unexpected\n");
			free(temp1);
			write(2, err_msg, _strlen(err_msg));
			free(err_msg);
			return (1);
		}
	}

	return (0);
}


/**
 * gen_ldkslfjds - generate an array of linked list pointers
 * @str: the string to be searched through
 * @delim: the delimeter
 *
 * Return: the head of the sll
 */
sll **gen_in_l(sll **input_list, char *s, char *prog_name)
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
		input_list[i + 1] = NULL;
		return (input_list);
	}

	/* check for syntax errors */
	if (check_input_syntax(s, prog_name))
	{
		free(input_list);
		return (NULL);
	}

	while(s[i])
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


