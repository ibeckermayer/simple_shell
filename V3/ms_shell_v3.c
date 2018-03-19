#include "ss_head.h"
/**
* main - medium version of shell w/continue prompt & added command functionality
* Return: 0
*/

int main(int argc, char **argv)
{
	char *buffer = NULL; /* *to_run = NULL; */
	char *arguments[_BUFSIZ], *history[HISTORY_COUNT];
	char *full_prog_path;
	char *err_msg = _strcat(argv[0], ": No such file or directory\n");
	int err_msg_len = _strlen(err_msg);
	int status, i, current = 0;

	UNUSED(argc);
	while (1)
	{
		show_prompt();
		buffer = get_input();

		/* Add to history */

        while (i < HISTORY_COUNT)
                history[i++] = NULL;

        history[current] = _strdup(buffer);
        current++;

        /* check for built-ins */

		if (_strcmp(buffer, "history") == 0 || _strcmp(buffer, "h") == 0)
		{
			_shistory(history, current);
			continue;
		}
		else if (_strcmp(buffer, "clear") == 0)
		{
			_sclear();
			continue;
		}
		else if (_strcmp(buffer, "exit") == 0 || _strcmp(buffer, "quit") == 0)
		{
			_sclear();
			_sexit();
		}
		else if (_strcmp(buffer, "env") == 0)
		{
			print_env();
			continue;
		}

		full_prog_path = f_cmd(strtok(strdup(buffer), " "));

		/* need to reset strtok because f_cmd calls it and is static*/
		strtok(buffer, " ");

		if (full_prog_path && _strcmp("", full_prog_path) != 0)
		{
			i = 0;
			arguments[i] = full_prog_path;
			while (arguments[i])
				arguments[++i] = strtok(NULL, " ");
			arguments[i] = NULL;

			if (!(fork()))
				execve(arguments[0], arguments, NULL);
			else
				wait(&status);
		}
		else if (full_prog_path && _strcmp("", full_prog_path) == 0)
		{
			write(2, err_msg, err_msg_len);
		}

		i = 0;
		printf("\n**********ON-GOIN History*************\n");
		while (history[i])
		{
			printf("%s\n", history[i++]);
		}
		printf("\n");
	}
}
