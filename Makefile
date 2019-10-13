# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 08:54:45 by lbarthon          #+#    #+#              #
#    Updated: 2019/10/13 11:50:25 by lbarthon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=@gcc
CFLAGS=-Wall -Werror -Wextra -I includes

NAME=libftprintf.a
SRCS=./srcs/args_module.c \
	 ./srcs/char_conversion.c \
	 ./srcs/flags_module.c \
	 ./srcs/float_conversion.c \
	 ./srcs/ft_contains.c \
	 ./srcs/ft_isprintf.c \
	 ./srcs/ft_ldtoa.c \
	 ./srcs/ft_lltohex.c \
	 ./srcs/ft_lltooctal.c \
	 ./srcs/ft_printf.c \
	 ./srcs/ft_putnbr_printf.c \
	 ./srcs/ft_starts_with.c \
	 ./srcs/hex_conversion.c \
	 ./srcs/hex_maj_conversion.c \
	 ./srcs/int_conversion.c \
	 ./srcs/lengths.c \
	 ./srcs/octal_conversion.c \
	 ./srcs/percent_conversion.c \
	 ./srcs/print_module.c \
	 ./srcs/ptr_conversion.c \
	 ./srcs/str_conversion.c \
	 ./srcs/struct_module.c \
	 ./srcs/unsigned_conversion.c \
	 ./srcs/utils.c
OBJ=$(SRCS:.c=.o)

LIB_DIR=libft
LIB_NAME=$(LIB_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIB_NAME) $(OBJ)
	@libtool -static -o $(NAME) $^

$(LIB_NAME):
	@make -C $(LIB_DIR)

clean:
	@make -C $(LIB_DIR) clean
	@rm -f $(OBJ)

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
