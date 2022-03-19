# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yun <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 10:31:34 by yun               #+#    #+#              #
#    Updated: 2021/06/26 14:36:22 by yun              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S	= push_swap

CC	= clang

FLAGS	= -Wall -Wextra -Werror

DIR_S	= srcs/push_swap_srcs/

DIR_LIB	= header/
		
SRCS_S =	$(DIR_S)push_swap.c	\
		$(DIR_S)swap.c	\
		$(DIR_S)utils.c	\
		$(DIR_S)utils_plus.c	\
		$(DIR_S)tools.c	\
		$(DIR_S)get_next_line.c	\
		$(DIR_S)get_next_line_utils.c	\
		$(DIR_S)push.c	\
		$(DIR_S)check_lst.c	\
		$(DIR_S)pivot.c	\
		$(DIR_S)sort.c	\
		$(DIR_S)sort_short.c	\
		$(DIR_S)sort_tools.c	\

OBJS_S	=	$(SRCS_S:%.c=%.o)

.c.o:
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I./$(DIR_LIB)

all: $(NAME_S)

$(NAME_S):	$(OBJS_S) $(DIR_LIB)
		$(CC) $(FLAGS) $(OBJS_S) -o $(NAME_S)

clean:
	rm -f $(OBJS_S)

fclean:	clean
	rm -f $(NAME_S)

re: fclean all

.PHONY:	re all clean fclean
