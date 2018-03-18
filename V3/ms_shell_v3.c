#include "ss_head.h"
/**
* main - medium version of shell w/continue prompt & added command functionality
* Return: 0
*/

int main(int argc, char **argv)
{
	char *buffer = NULL; /* *to_run = NULL; */
	char *arguments[_BUFSIZ];
	char *full_prog_path;
	char *err_msg = _strcat(argv[0], ": No such file or directory\n");
	int err_msg_len = _strlen(err_msg);
	int status, i;

	UNUSED(argc);
	while (1)
	{
		show_prompt();
		buffer = get_input();
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


	}
}
