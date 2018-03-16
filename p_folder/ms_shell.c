#include "ss_head.h"

char *show_prompt(char *buffer)
{
	int i = 0;
	buffer = getinput();

	while (buffer[i] != '\n')
		i++;

	buffer[i] = 0;

	return (buffer);

}

int main(int argc, char **argv)
{
	size_t buffsize = 32;
	char *buffer = NULL, *token = NULL, *to_run;
	char *execve_seed[]= {to_run, NULL};


	const char delim[2] = " ";
	int i = 0, status;

	buffer = show_prompt(buffer);

	execve_seed[0] = to_run = token = strtok(buffer, delim);

	i = 0;
	while (1)
	{
		if (fork() == 0)
		{
			execve(execve_seed[0], execve_seed, NULL);
		}
		else
		{
			wait(&status);
			execve_seed[0] = to_run = token = strtok(show_prompt(buffer), delim);
		}
	} 
}
