#include "ss_head.h"

void _control_c(int sig)
{
	/* ctrl_c = 1; */
	/* printf("\n"); */
	signal(sig, SIG_IGN);
}
