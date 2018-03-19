#include "ss_head.h"
/**
 * _history - clear the screen
 * Return: void
 */
void pr_int(int n);
void _shistory(char **history, int current)
{
        int i = 0;

        while (history[i])
        {
                write(1, " ", 1);
                write(1, "  ", 2);
                write(1, history[i++], _strlen(history[i]));
                write(1, "\n", 1);
        }

}