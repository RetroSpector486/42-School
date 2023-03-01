# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 11:56:32 by kbolzon           #+#    #+#              #
#    Updated: 2023/02/21 12:35:51 by kbolzon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = ./operations/push.c \
				./operations/reverse.c \
				./operations/swap.c \
				./operations/rotate.c \
				./srcs/main.c \
				./srcs/init.c \
				./srcs/input_check.c \
				./srcs/moves.c \
				./srcs/stack.c \
				./srcs/utils.c \
				./srcs/check_utils.c \
				./sort/move.c \
				./sort/pos.c \
				./sort/sort_small.c \
				./sort/sort.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(SRCS) -Iheaders -o $(NAME)

all: $(NAME)

clean:
		@rm -rf ./operations/*.o
		@rm -rf ./srcs/*.o
		@rm -rf ./sort/*.o
fclean: clean
		@rm -rf $(NAME)

re: fclean all
