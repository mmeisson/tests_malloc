
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

#include "ft_stdio.h"
#include "test.h"

int		test_4(backtrace bt)
{
	void		*data[MAX_ALLOC];

	bt_push(bt, __FUNCTION__);
	for (size_t i = 1; i < MAX_ALLOC; i += INCR) {
		bt_push(bt, "malloc");
		data[i] = malloc(i);
		bt_pop(bt);

		TEST_NULL(data[i]);

#ifdef CHECK_ALIGN
		if ((uintptr_t)data[i] % 16 != 0) {
			ft_dprintf(STDERR_FILENO, "malloc(%zu) returned a non aligned boundary", i);
			bt_pop(bt);
			return -1;
		}
#endif
	}

	for (size_t i = 1; i < MAX_ALLOC; i += INCR) {
		bt_push(bt, "first memset");
		memset(data[i], 'a', i);
		bt_pop(bt);
	}

	for (size_t i = 1; i < MAX_ALLOC; i += INCR) {
		char		cmp[i];

		memset(cmp, 'a', i);

		bt_push(bt, "memcmp");
		bt_pop(bt);
		if (memcmp(cmp, data[i], i) != 0) {
			ft_dprintf(STDERR_FILENO, "Segment %zu is corrupted", i);
			bt_pop(bt);
			return -1;
		}
		bt_pop(bt);

		bt_push(bt, "free");
		free(data[i]);
		bt_pop(bt);
	}
	bt_pop(bt);
	return 0;
}
