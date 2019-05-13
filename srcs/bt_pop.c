
#include <stdlib.h>
#include "test.h"

void	bt_pop(backtrace bt)
{
	size_t		i;

	if (bt)
	{
		for (i = 0; bt[i][0] != '\0'; i++) { }

		if (i > 0) {
			bt[i - 1][0] = 0;
		}
	}
}
