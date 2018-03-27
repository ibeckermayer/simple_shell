#include "ss_head.h"

/**
 * shifthis - shifts the history buffer down once it reaches its memory limit
 * @history: the history buffer
 *
 * Return: void
 */
void shifthis(char **history)
{
	int i;

	for (i = 1; i < HISTORY_COUNT - 1; i++)
		history[i - 1] = history[i];
}

/**
 * _shistory - clear the screen
 * @input: the input taken from the main
 * @add: if 1, we are adding to the history. if 0, we are displaying it.
 *
 * Return: void
 */
void _shistory(char *input, int add)
{
	int i = 0;
	int his_num;
	int his_tot;
	static int cur_his;
	static char *history[HISTORY_COUNT];
	char *num;

	if (add)
	{
		if (cur_his < HISTORY_COUNT)
		{
			history[cur_his] = _strdup(input);
			cur_his++;
		}
		else
		{
			shifthis(history);
			history[HISTORY_COUNT - 1] = _strdup(input);
			cur_his++;
		}
	}
	else
	{
		if (cur_his >= HISTORY_COUNT)
			his_tot = HISTORY_COUNT;
		else
			his_tot = cur_his;

		while (i < his_tot)
		{
			if (cur_his >= HISTORY_COUNT)
				his_num = cur_his - HISTORY_COUNT + i + 1;
			else
				his_num = i + 1;

			if (his_num < 10)
				write(1, "   ", 3);
			else if (his_num < 100)
				write(1, "  ", 2);
			else if (his_num < 1000)
				write(1, " ", 1);

			num = _itoa(his_num, 10);
			write(1, num, _strlen(num));
			write(1, "  ", 2);
			write(1, history[i], _strlen(history[i]));
			i++;
			write(1, "\n", 1);
		}
	}
}
