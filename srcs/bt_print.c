

#include <stdlib.h>
#include <unistd.h>
#include "test.h"

void	bt_print(backtrace bt)
{
	size_t		i;

	if (bt)
	{
		for (i = 0; bt[i][0] != '\0'; i++) {
			ft_dprintf(STDERR_FILENO, "-> [%s] ", bt[i]);
		}
	}

}
