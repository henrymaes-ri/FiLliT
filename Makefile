# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hemaes-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/21 15:29:34 by hemaes-r          #+#    #+#              #
#    Updated: 2018/05/21 15:30:10 by hemaes-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS = main.c read_it.c validate_it.c solve_it.c use_it.c use_it2.c
OBJS = $(SRCS:.c=.o)
INCL = -I fillit.h

.PHONY:	all clean fclean re
	
all: $(NAME)

$(OBJS): %.o:%.c
	@$(CC) $(FLAGS) $(INCL) -o $@ -c $^

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
