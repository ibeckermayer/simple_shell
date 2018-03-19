#include "ss_head.h"
/**
 * _history - clear the screen
 * Return: void
 */
void _shistory(char **history)
{
        int i = 0;
        char *num;

        while (history[i])
        {
                if (i + 1 < 10)
                        write(1, "   ", 3);
                else if (i + 1 < 100)
                        write(1, "  ", 2);
                else if (i + 1 < 1000)
                        write(1, " ", 1);

                num = _itoa(i + 1, 10);
                write(1, num, _strlen(num));
                write(1, "  ", 2);
                write(1, history[i], _strlen(history[i]));
                i++;
                write(1, "\n", 1);
        }

}
