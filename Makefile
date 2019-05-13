
INCS_PATHS		= ./ ../incs ./printf/incs

NAME			= test_malloc

CC				= gcc

CFLAGS			= -O0 -Wall -Wextra

VPATH			= ./srcs

SRCS			= test_0.c
SRCS			+= test_1.c
SRCS			+= test_2.c
SRCS			+= test_3.c
SRCS			+= test_4.c
SRCS			+= test_5.c
SRCS			+= test_6.c
SRCS			+= test_7.c
SRCS			+= test_8.c
SRCS			+= test_9.c
SRCS			+= test_10.c
SRCS			+= test_11.c
SRCS			+= test_12.c

SRCS			+= bt_push.c
SRCS			+= bt_print.c
SRCS			+= bt_pop.c

ifeq ($(MALLOC_THREADED),THREADED)
	SRCS		+= main_thread.c
else
	SRCS		+= main_fork.c
endif

INCS			= $(addprefix -I,$(INCS_PATHS))

OBJS_PATH		= ./.objs/
OBJS_NAME		= $(SRCS:.c=.o)
OBJS			= $(addprefix $(OBJS_PATH), $(OBJS_NAME))

DEPS			= $(OBJS:.o=.d)


all: $(NAME)


$(NAME): $(OBJS)
	make -j8 -C ./printf/
	$(CC) $^ -o $@ -L printf -lftprintf -lpthread

$(OBJS_PATH)%.o: %.c Makefile
	@mkdir -p $(OBJS_PATH)
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

clean:
	rm -rf $(OBJS_PATH)

fclean:
	rm -rf $(OBJS_PATH)
	rm -f $(NAME)

re:
	make fclean
	make -j32 all

test: $(NAME)
	./run.sh ./$(NAME) $(ARGS)

-include $(DEPS)
