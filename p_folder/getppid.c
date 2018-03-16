#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	unsigned long long int pid_max = 0;
	int i = 0;

	size_t buffsize = 32;
	size_t chars;
	char *buffer = NULL;

	const char delim[2] = " ";
	char *token = NULL;

	pid_t parent, child;
	int status;

	pid_max = ~pid_max;

	printf("parent id is: %u\n", getppid());
	printf("max is: %u\n", (pid_t)pid_max);

	while (argv[i])
	{
		printf("argv[%d] is: %s\n", i, argv[i]);
		i++;
	}

	printf("for seg\n");


	printf("$ ");
	chars = getline(&buffer, &buffsize, stdin);

	printf("%s", buffer);

	token = strtok(buffer, delim);

	while (token != NULL)
	{
		printf("%s ", token);
		token = strtok(NULL, delim);

	}

	char *a[]= {"/bin/ls", "-l", "/tmp", NULL};

	printf("Parent process is: %u\n", getpid());

	// i = 0;
	// child = 1;

	// while (i < 5)
	// {
	// 	if (child == 0)
	// 	{
	// 			if (execve(a[0], a, NULL) == -1)
	// 			{
	// 				printf("Error\n");
	// 			}
	// 	}
	// 	else
	// 	{
	// 		child = fork();

	// 		if (child)
	// 		{
	// 			printf("Parent process forked, chid is: %u\n", child);
	// 			if (i = 4)
	// 				break;
	// 			wait(&status);
	// 			i++;
	// 		}
	// 	}
	// }

	i = 0;

	while (i < 5)
	{
		if (fork() == 0)
		{
			execve(a[0], a, NULL);
		}
		else
		{
			i++;
			wait(&status);
		}
	} 



	




}
