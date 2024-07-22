# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: valvarez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 16:07:55 by valvarez          #+#    #+#              #
#    Updated: 2024/04/19 16:07:58 by valvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

RM = rm -rf

NAME = libftprintf.a

SRC =	ft_itoa.c		\
		ft_putchar_fd.c	\
		ft_printf.c		\
		ft_print_ptr.c	\
		ft_print_unsigned.c	\
		ft_printf_utils.c	\
		ft_print_hex.c	\

FLAGS = -Wall -Wextra -Werror -c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re