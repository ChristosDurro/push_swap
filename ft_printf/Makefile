SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putlnbr_base.c ft_putunbr_base.c ft_check_base.c \
	ft_string_format.c ft_integer_format.c ft_pointer_format.c ft_unsigned_format.c ft_hex_format.c ft_initialise.c \
	libft/ft_isdigit.c libft/ft_strncmp.c libft/ft_strlen.c libft/ft_atoi.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./lbift

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}	

bonus: all

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re
