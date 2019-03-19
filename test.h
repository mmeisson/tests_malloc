#ifndef TEST_H
# define TEST_H

# include <stdlib.h>
# include "ft_stdio.h"

# define MSG_MAX_LEN	80
# define MAX_MSG		80

typedef char		backtrace[MSG_MAX_LEN][MAX_MSG];

# define MAX_ALLOC		5000
# define INCR			3
# define CHECK_ALIGN	1
# define SAFE			1

# if SAFE == 1
#  define TEST_NULL(addr) if (addr == NULL) { ft_dprintf(STDERR_FILENO, "Received an unexpected NULL function %s line %d", __FUNCTION__, __LINE__); exit(EXIT_FAILURE); }
# else
#  define TEST_NULL(addr) ((void)addr)
# endif

int		test_0(backtrace bt);
int		test_1(backtrace bt);
int		test_2(backtrace bt);
int		test_3(backtrace bt);
int		test_4(backtrace bt);
int		test_5(backtrace bt);
int		test_6(backtrace bt);
int		test_7(backtrace bt);
int		test_8(backtrace bt);
int		test_9(backtrace bt);
int		test_10(backtrace bt);
int		test_11(backtrace bt);
int		test_12(backtrace bt);

void	bt_push(backtrace bt, const char *msg);
void	bt_pop(backtrace bt);
void	bt_print(backtrace bt);

#endif
