
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

#include "ft_stdio.h"
#include "test.h"

int		test_1(backtrace bt)
{
	bt_push(bt, __FUNCTION__);
	for (size_t i = 1; i < MAX_ALLOC; i += INCR) {

		bt_push(bt, "malloc");
		void	*data = malloc(i);
		bt_pop(bt);

		TEST_NULL(data);

#ifdef CHECK_ALIGN
		if ((uintptr_t)data % 16 != 0) {
			ft_dprintf(STDERR_FILENO, "malloc(%zu) returned a non aligned boundary", i);
			bt_pop(bt);
			return -1;
		}
#endif
		bt_push(bt, "memset");
		memset(data, 'a', i);
		bt_pop(bt);

		bt_push(bt, "free");
		free(data);
		bt_pop(bt);
	}
	bt_pop(bt);
	return 0;
}
