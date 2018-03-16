#include "ss_head.h"

int main(int argc, char **argv)
{
	size_t buffsize = 32;
	size_t chars;
	char *buffer = NULL, *token = NULL, *to_run;
	char *execve_seed[]= {to_run, NULL};


	const char delim[2] = " ";
	int i = 0, status;

	printf("$ ");
	chars = getline(&buffer, &buffsize, stdin);

	while (buffer[i] != '\n')
		i++;

	buffer[i] = 0;

	execve_seed[0] = to_run = token = strtok(buffer, delim);

	i = 0;
	while (i < 1)
	{
		if (fork() == 0)
		{
			execve(execve_seed[0], execve_seed, NULL);
		}
		else
		{
			i++;
			wait(&status);
		}
	} 
}
