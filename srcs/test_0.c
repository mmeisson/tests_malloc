
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

#include "ft_stdio.h"
#include "test.h"

int     test_0(backtrace bt)
{
    bt_push(bt, __FUNCTION__);

    bt_push(bt, "malloc");
    void        *data = malloc(0);
    int         res = 0;
    bt_pop(bt);

    if (data == NULL) {
        return 0;
    }
#ifdef CHECK_ALIGN
    if ((uintptr_t)data % 16 != 0) {
        ft_dprintf(STDERR_FILENO, "malloc(0) returned a non aligned boundary");
        res =  -1;
    }
#endif
    bt_push(bt, "free");
    free(data);
    bt_pop(bt);
    return res;
}
