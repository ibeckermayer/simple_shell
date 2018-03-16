#include "ss_head.h"


int _getppid(void)
{
	char *execve_seed[]= {"/bin/echo $$", NULL};
	int status, i = 0;

	while (execve_seed[0][i])
		i++;
	execve_seed[i] = 0;

	if (!fork())
		printf("%d\n", execve(execve_seed[0], execve_seed, NULL));
	else
		wait(&status);
	return (0);
}

int main (void)
{
	_getppid();
	return (0);
}