
#include <stdlib.h>
#include <string.h>

#include "test.h"

void		bt_push(backtrace bt, const char *msg)
{
	size_t		i;

	if (bt)
	{
		for (i = 0; bt[i][0] != '\0'; i++) {}

		strcpy(bt[i], msg);
	}
}
