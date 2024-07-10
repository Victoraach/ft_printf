NAME = libftprintf.a
CC = gcc -c
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
SRCS =	ft_print_char.c \
		ft_print_str.c \
		ft_printf.c \
		ft_printn_base.c \
		ft_printnu_base.c \
		ft_print_hex.c \
		ft_strlenv2.c \

OBJS = ${SRCS:.c=.o}

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
.PHONY: all clean fclean re
