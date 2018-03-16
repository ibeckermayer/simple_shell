#include "ss_head.h"

/**
* main - medium version of shell w/continue prompt
* Return: 0
*/

int main(int argc, char **argv)
{
	size_t buffsize = 32;
	char *buffer = NULL, *token = NULL, *to_run;
	char *execve_seed[]= {to_run, NULL};


	const char delim[2] = " ";
	int i = 0, status;

	buffer = show_prompt(find_command(buffer));

	execve_seed[0] = to_run = token = strtok(buffer, delim);

	i = 0;
	while (1)
	{
		if (fork() == 0)
			execve(execve_seed[0], execve_seed, NULL);
		else
		{
			wait(&status);
			execve_seed[0] = to_run = token = strtok(show_prompt(find_command(buffer)), delim);
		}
	} 
}
