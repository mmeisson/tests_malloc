# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeisson <mmeisson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/14 21:39:23 by mmeisson          #+#    #+#              #
#    Updated: 2016/08/31 11:28:48 by mmeisson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PATH = ./srcs/
SRC_NAME = ft_printchars.c ft_printhexa.c ft_printlong.c ft_printlonglong.c\
		   ft_printlonglongoctal.c ft_printlonglonghexa.c ft_printlongoctal.c\
		   ft_printlonghexa.c ft_printint.c ft_printptr.c ft_printwstr.c\
		   ft_printlib1.c ft_printparsing.c ft_printget.c ft_printoctal.c\
		   ft_printwchar.c ft_printprecision.c ft_mask_first.c ft_mask_sec.c\
		   ft_printflush.c ft_printlib2.c ft_print_width.c\
		   \
		   ft_printf.c ft_dprintf.c\

OBJ_PATH = ./.objs/
OBJ_NAME = $(SRC_NAME:.c=.o)

INC_PATH = ./incs/

CFLAGS = -Wall -Wextra -Werror -Ofast -Wno-unused-result

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))



all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all
