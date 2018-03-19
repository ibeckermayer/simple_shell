#include "ss_head.h"
/**
 * _history - clear the screen
 * Return: void
 */
void _shistory(char **history)
{
        int i = 0;
	int his_num;
	int his_tot;
        char *num;

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
