#include "ss_head.h"

void shifthis(void)
{
	int i;

	for (i = 1; i < HISTORY_COUNT - 1; i++)
		history[i - 1] = history[i];
}

void add2his(char *input)
{
	if (cur_his < HISTORY_COUNT)
	{
		history[cur_his] = _strdup(input);
		cur_his++;
	}
	else
	{
		shifthis();
		history[HISTORY_COUNT - 1] = _strdup(input);
		cur_his++;
	}
}
