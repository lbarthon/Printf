# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 08:54:45 by lbarthon          #+#    #+#              #
#    Updated: 2018/11/28 13:41:53 by lbarthon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=@gcc
CFLAGS=-Wall -Werror -Wextra -I includes

NAME=libftprintf.a
SRCS=./srcs/args_module.c \
	 ./srcs/ft_atoi.c \
	 ./srcs/ft_isalpha.c \
	 ./srcs/ft_isdigit.c \
	 ./srcs/ft_printf.c \
	 ./srcs/ft_putstr.c \
	 ./srcs/ft_starts_with.c \
	 ./srcs/ft_strdup.c \
	 ./srcs/lengths.c \
	 ./srcs/print_module.c \
	 ./srcs/str_conversion.c \
	 ./srcs/struct_module.c
OBJ=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
