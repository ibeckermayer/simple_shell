#include "ss_head.h"

int main(int argc, char **argv, char **environ)
{
	int i = 0;

	while (environ[i])
		printf("%s\n", environ[i++]);

	return (0);
}