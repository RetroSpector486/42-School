# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 12:02:06 by kbolzon           #+#    #+#              #
#    Updated: 2022/03/16 12:51:04 by kbolzon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = srcs/intunsignedint.c \
				srcs/hex-pointer-string-character.c \
				srcs/ft_printf.c \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
		gcc -c $(CFLAGS) -I headers $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(MAKE) -C ./libft
		cp libft/libft.a $(NAME)
		ar -rcs $(NAME) $(OBJS)

clean:
		$(MAKE) clean -C ./libft
		rm -f $(NAME) $(OBJS)

fclean:
		$(MAKE) clean -C ./libft
		rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all, clean, fclean, re