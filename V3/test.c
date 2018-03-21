#include "ss_head.h"
/**
 * tests - checker
 *
 * Return: void
 */

void tests(void)
{
	char *input;

	write(1, "\n***;)******;)*********;)*****\n", 32);
	write(1, "*******************WELCOME****\n", 31);
	write(1, "*********;)*******TO**********\n", 31);
	write(1, "***************THE*****;)*****\n", 31);
	write(1, "**;)******CHECKER*************\n", 31);
	write(1, "*****;)********;)******;)*****\n\n", 32);

	while (1)
	{
		write(1, "test prompt > ", 15);

		input = get_input();

		if (_strcmp(input, "exit") == 0)
		{
			_sclear();
			break;
		}
		else if (_strcmp(input, "c") == 0)
		{
			_sclear();
			continue;
		}

		sll *head = gen_sll(input, INPUT_DELIM);

		/* check get_input is working */
		assert(input != NULL);

		/* check get_sll is working */
		assert(head != NULL);

		while (head)
		{
			free(head->str);
			head = head->next;
		}

		/* example of checking for free success */
		assert(head == NULL);

		/* will only print if all tests are successful */
		printf("No errors.\n");
	}
}
