# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 15:47:25 by kbolzon           #+#    #+#              #
#    Updated: 2023/03/20 15:07:36 by kbolzon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders/

MINILIBX := mlx_linux/
LIBRARY := -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

SRCS :=			./srcs/args.c \
				./srcs/colors.c \
				./srcs/events.c \
				./srcs/fractol.c \
				./srcs/init.c \
				./srcs/msgs.c \
				./srcs/render.c \
				./srcs/utils.c \
				./srcs/schemes/color_special.c \
				./srcs/schemes/interpolated_color.c \
				./srcs/schemes/striped_color.c \
				./srcs/sets/julia.c \
				./srcs/sets/mandelbox.c \
				./srcs/sets/mandelbrot.c \
				./srcs/sets/burning_ship.c \
				./srcs/utils/ft_bzero.c \
				./srcs/utils/ft_calloc.c \
				./srcs/utils/ft_isdigit.c \
				./srcs/utils/ft_ishexdigit.c \
				./srcs/utils/ft_isspace.c \
				./srcs/utils/ft_putchar_fd.c \
				./srcs/utils/ft_putendl_fd.c \
				./srcs/utils/ft_putstr_fd.c \
				./srcs/utils/ft_strchr.c \
				./srcs/utils/ft_memset.c \
				./srcs/utils/ft_strlen.c \
				./srcs/utils/ft_strncmp.c \
				./srcs/utils/ft_tolower.c \
				./srcs/utils/ft_toupper.c \

OBJS := $(SRCS:.c=.o)

all:  
		make -C $(MINILIBX)
		$(CC) $(CFLAGS) $(SRCS) $(LIBRARY) -o $(NAME)

clean:	

fclean: clean
				make clean -C $(MINILIBX)
				rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re