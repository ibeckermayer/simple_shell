#include "ss_head.h"

void _control_c(int sig)
{
     signal(sig, SIG_IGN);
}