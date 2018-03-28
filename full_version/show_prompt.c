#include "ss_head.h"

/**
* show_prompt - shows prompt
*
* Return: void
*/
void show_prompt(void)
{
	write(1, PROMPT, PROMPT_LEN);
}
