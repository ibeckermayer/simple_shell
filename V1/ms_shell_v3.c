#include "ss_head.h"
/**
* main - medium version of shell w/continue prompt & added command functionality
* Return: 0
*/

int main(void)
{
	char *buffer = NULL; /* *to_run = NULL; */
	char *execve_seed[2];
	/* const char delim[2] = " "; */
	int status;

	execve_seed[1] = NULL;

	while (1)
	{
		show_prompt();
		buffer = get_input();
		/* execve_seed[0] = to_run = strtok(buffer, delim); */
		/* execve_seed[0] = strtok(buffer, delim); */
		execve_seed[0] = buffer;
		if (!(fork()))
		{
			execve(execve_seed[0], execve_seed, NULL);
		}
		else
		{
			wait(&status);
		}
	} 
}
