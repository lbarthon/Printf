# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 08:54:45 by lbarthon          #+#    #+#              #
#    Updated: 2019/10/13 14:57:01 by lbarthon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=@gcc
CFLAGS=-Wall -Werror -Wextra -I includes

NAME=libftprintf.a
SRCS=./srcs/ft_printf.c \
		 ./srcs/modules.c \
		 ./srcs/buffer.c

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
