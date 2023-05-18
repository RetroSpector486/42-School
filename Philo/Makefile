# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 12:55:35 by kbolzon           #+#    #+#              #
#    Updated: 2023/05/09 14:26:07 by kbolzon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

NAME_BONUS = philo_bonus

CC =  gcc

FLAGS = -pthread -Wall -Werror -Wextra

SRCS = 			./srcs/actions.c \
				./srcs/init.c \
				./srcs/parsing.c \
				./srcs/philo.c \

OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
				$(CC) $(FLAGS) $(SRCS) -Iheaders -o $(NAME)

all: $(NAME)

clean: 
				@rm -rf $(OBJS)

fclean: clean
				@rm -rf $(NAME)

re: fclean all