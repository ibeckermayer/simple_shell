#include "ss_head.h"
/**
* main - medium version of shell w/continue prompt & added command functionality
* Return: 0
*/

int main(void)
{
	char *buffer = NULL; /* *to_run = NULL; */
	char *arguments[_BUFSIZ];
	/* const char delim[2] = " "; */
	int status, i;


	while (1)
	{
		show_prompt();
		buffer = get_input();
		i = 0;
		arguments[i] = strtok(buffer, " ");
		while (arguments[i])
			arguments[++i] = strtok(NULL, " ");
		arguments[i] = NULL;

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
