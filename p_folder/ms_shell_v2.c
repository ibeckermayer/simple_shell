#include "ss_head.h"
#include "f_cmd.c"
/**
* main - medium version of shell w/continue prompt & added command functionality
* Return: 0
*/

int main(int argc, char **argv)
{
	size_t buffsize = 32;
	char *buffer = NULL, *token = NULL, *to_run, *tmp;
	char *execve_seed[]= {to_run, NULL};


	const char delim[2] = " ";
	int i = 0, status;

	tmp = show_prompt(tmp);
	printf("tmp first time is: %s\n", tmp);
	buffer = f_cmd(tmp, _getenv("PATH"));
	printf("command is: %s\n", buffer);
	execve_seed[0] = to_run = token = strtok(buffer, delim);

	i = 0;
	while (1)
	{
		if (!(fork()))
		{
			execve(execve_seed[0], execve_seed, NULL);
		}
		else
		{
			printf("child process is: %u\n", getpid());
			printf("parent is: %u\n", getppid());
			printf("path is: %s\n", _getenv("PATH"));
			printf("command second time: %s\n", buffer);
			wait(&status);
		}

		tmp = show_prompt(tmp);
		buffer = f_cmd(tmp, _getenv("PATH"));
		execve_seed[0] = to_run = token = strtok(buffer, delim);
	} 
}
