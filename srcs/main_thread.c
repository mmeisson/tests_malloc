
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <pthread.h>

#include "test.h"
#include "ft_stdio.h"

typedef int (*c_test)(backtrace bt);

backtrace bt = {0};

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

int main(void)
{
	c_test tests[] = {
		test_0, test_1, test_2, test_3, test_4, test_5, test_6, test_7, test_8, test_9, test_10, test_11, test_12};
	const size_t tests_nb = ARRAY_SIZE(tests);
	pthread_t pids[tests_nb];

	for (size_t i = 0; i < tests_nb; i++)
	{
		pthread_create(&pids[i], NULL, tests[i], NULL);
	}

	for (size_t i = 0; i < tests_nb; i++)
	{
		pthread_join(pids[i], NULL);
	}
	return EXIT_SUCCESS;
}
