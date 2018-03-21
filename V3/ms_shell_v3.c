#include "ss_head.h"
/**
 * main - medium version of shell w/continue prompt & added cmd functionality
 * @argc: argument count
 * @argv: argument buffer
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *input = NULL; /* *to_run = NULL; */
	char *arguments[_BUFSIZ];
	char *full_prog_path;
	char *err_msg = malloc(_BUFSIZ);
	int status, i;
	sll *input_toks;

	/* checks to see if global error is 0 to  start counting at 1 */
	if (!num_errors)
		num_errors++;

	UNUSED(argc);

	while (1)
	{
		/* check control-c */
		signal(SIGINT, _control_c);

		/* Check for interative vs. non-interative mode */
		if (isatty(0))
			show_prompt();

		/* get input */
		input = get_input();

		/* Add to history unless it is an empty string or return*/
		if (_strcmp(input, "\n") != 0)
		{
			_shistory(input, 1);
		}

		/* tokenize input  unless it's cd*/
		input_toks = gen_sll(input, INPUT_DELIM);

		/* check for built-ins */
		if (check_builtins(input_toks) == 0)
			continue;

		if (input_toks)
			full_prog_path = f_cmd(input_toks->str);
		else
			full_prog_path = NULL;

		if (full_prog_path && _strcmp("", full_prog_path) != 0)
		{
			i = 0;
			arguments[i++] = full_prog_path;
			input_toks = input_toks->next;
			while (input_toks)
			{
				arguments[i] = input_toks->str;
				input_toks = input_toks->next;
				i++;
			}
			arguments[i] = NULL;

			if (!(fork()))
				execve(arguments[0], arguments, NULL);
			else
				wait(&status);
		}
		else if (full_prog_path && _strcmp("", full_prog_path) == 0)
		{
			err_msg = get_error(argv[0] + 2, num_errors, input_toks);
			write(2, err_msg, _strlen(err_msg));
			num_errors++;
		}
		else
			continue;
	}
}
