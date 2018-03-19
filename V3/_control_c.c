#include "ss_head.h"

void _control_c(int sig)
{ 
     UNUSED(sig);
     write(1, "\n", 1);
     show_prompt();
}
