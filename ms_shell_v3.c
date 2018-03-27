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
	sll **input_list = _calloc(_BUFSIZ);
	char *full_prog_path;
	char *err_msg;
	int status, i, k;
	/* pid_t stats; */
	/* pid_t _pid; */
	sll *input_toks;

	/* checks to see if global error is 0 to  start counting at 1 */
	if (!num_errors)
		num_errors++;

	UNUSED(argc);

	extract_env();
	while (1)
	{

		/* _setenv the program name */
		_setenv("_", argv[0], 1);

		/* check control-c */
		signal(SIGINT, _control_c);

		/* Check for interative vs. non-interative mode */
		if (isatty(0))
			show_prompt();

		/* get input */
		input = get_input();

		/*
		  !!! not quite the behavior - adds history if history isn't the last command...
		   Add to history unless it is an empty string or return or history
		*/
		if (_strcmp(input, "\n") == 0)
			;
		else if (check_for_his(input, "history") == 1)
			;
		else if (check_for_his(input, "h") == 1)
			;
		else
			_shistory(input, 1);

		/* generate list of separate commands */
		input_list = gen_in_l(input_list, input);

		/* free the input, no longer needed */
		free(input);

		k = 0;
		do
		{
			input_toks = input_list[k++];

			/* !!! probably need to check here if the input
			 is exit or CTRL-D in order to free memory before
			_exit() is called */

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
				{
					if (!recall_path)
						free(full_prog_path);
					wait(&status);
				}
			}
			else if (full_prog_path && _strcmp("", full_prog_path) == 0)
			{
				err_msg = get_error(argv[0], num_errors, input_toks);
				write(2, err_msg, _strlen(err_msg));
				free(err_msg);
				num_errors++;
			}
			else
			{
				free(full_prog_path);
				continue;
			}


		} while (input_list[k]);
		free_sll_l(input_list);
	}
}
