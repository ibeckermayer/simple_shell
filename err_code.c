#include "ss_head.h"

int *err_code(int *code)
{
	static int err_code;

	if (!code)
		return (&err_code);
	else
		err_code = *code;
	return (NULL);
}
