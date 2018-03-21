#include "ss_head.h"
/**
 * check_arr - check for arrow presses to go through history
 * @history: commands to go through
 * Return: void
 */

void check_arr(char **history)
{
	int i = 0;

	while (1)
	{
		show_prompt();
		if (getch() == '\033')
		{
		getch();
			switch (getch())
			{
				case 'A':
					write(1, history[i], _strlen(history[i]));
					write(1, "\n", 1);
					i++;
					break;
				case 'B':
					if (i >= 2)
						i -= 2;
					else
						i--;
					write(1, history[i], _strlen(history[i]));
					write(1, "\n", 1);
					i += 1;
					break;
				case 'C':
					goto end_loop;
				case 'D':
					/* code for arrow left */
					break;
			}
		}
	}
end_loop: write(1, "\n", 1);
}
