#include "ss_head.h"
/**
* main - medium version of shell w/continue prompt & added command functionality
* Return: 0
*/

int main(void)
{
	char *buffer = NULL; /* *to_run = NULL; */
	char *arguments[_BUFSIZ];
	char *full_prog_path;
	/* const char delim[2] = " "; */
	int status, i;


	while (1)
	{
		show_prompt();
		buffer = get_input();
		full_prog_path = f_cmd(strtok(strdup(buffer), " "));

		/* need to reset strtok because f_cmd calls it and is static*/
		strtok(buffer, " ");

		if (full_prog_path)
		{
			i = 0;
			arguments[i] = full_prog_path;
			while (arguments[i])
				arguments[++i] = strtok(NULL, " ");

			arguments[i] = NULL;
		}


		if (!(fork()))
		{
			execve(arguments[0], arguments, NULL);
		}
		else
		{
			wait(&status);
		}
	} 
}
