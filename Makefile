# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 08:54:45 by lbarthon          #+#    #+#              #
#    Updated: 2018/11/30 12:59:34 by lbarthon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=@gcc
CFLAGS=-g -Wall -Werror -Wextra -I includes

NAME=libftprintf.a
SRCS=./srcs/args_module.c \
	 ./srcs/char_conversion.c \
	 ./srcs/flags_module.c \
	 ./srcs/ft_contains.c \
	 ./srcs/ft_isprintf.c \
	 ./srcs/ft_printf.c \
	 ./srcs/ft_putnbr_printf.c \
	 ./srcs/ft_starts_with.c \
	 ./srcs/int_conversion.c \
	 ./srcs/lengths.c \
	 ./srcs/print_module.c \
	 ./srcs/str_conversion.c \
	 ./srcs/struct_module.c
OBJ=$(SRCS:.c=.o)

LIBFILES=./libft/ft_atoi.c \
		 ./libft/ft_isalpha.c \
		 ./libft/ft_isdigit.c \
		 ./libft/ft_nbrlength.c \
		 ./libft/ft_strdup.c \
		 ./libft/ft_putchar.c \
		 ./libft/ft_putnstr.c
LIBOBJ=$(LIBFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBOBJ)
	@ar -rcs $(NAME) $(OBJ) $(LIBOBJ)

clean:
	@rm -f $(OBJ) $(LIBOBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
