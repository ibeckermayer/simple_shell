#include "ss_head.h"
/**
 * main - medium version of shell w/continue prompt & added command functionality
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *input = NULL; /* *to_run = NULL; */
	char *arguments[_BUFSIZ], *history[HISTORY_COUNT];
	char *full_prog_path;
	char *err_msg = _strcat(argv[0], ": No such file or directory\n");
	int err_msg_len = _strlen(err_msg);
	int status, i, current = 0;
	sll *input_toks;

	UNUSED(argc);
	while (1)
	{
		/* display prompt and wait for input */
		show_prompt();
		input = get_input();

		/* Add to history */
		while (i < HISTORY_COUNT)
			history[i++] = NULL;
		history[current] = _strdup(input);
		current++;

		/* tokenize input */
		input_toks = gen_sll(input, INPUT_DELIM);

		/* check for built-ins */
		if (_strcmp(input, "history") == 0 || _strcmp(input, "h") == 0)
		{
			_shistory(history, current);
			continue;
		}
		else if (_strcmp(input, "clear") == 0)
		{
			_sclear();
			continue;
		}
		else if (_strcmp(input, "exit") == 0 || _strcmp(input, "quit") == 0)
		{
			_sclear();
			_sexit();
		}
		else if (_strcmp(input, "env") == 0)
		{
			print_env();
			continue;
		}

		full_prog_path = f_cmd(input_toks->str);

		/* /\* need to reset _strtok because f_cmd calls it and is static*\/ */
		/* _strtok(input, " "); */

		if (full_prog_path && _strcmp("", full_prog_path) != 0)
		{
			i = 0;
			arguments[i] = full_prog_path;
			while (arguments[i])
			{
				arguments[++i] = input_toks->str;
				input_toks = input_toks->next;
			}

			if (!(fork()))
				execve(arguments[0], arguments, NULL);
			else
				wait(&status);
		}
		else if (full_prog_path && _strcmp("", full_prog_path) == 0)
		{
			write(2, err_msg, err_msg_len);
		}
		else
			continue;

		/* i = 0; */
		/* printf("\n**********Perpetual History*************\n"); */
		/* while (history[i]) */
		/* { */
		/* 	printf("%s\n", history[i++]); */
		/* } */
		/* printf("\n"); */
	}
}
