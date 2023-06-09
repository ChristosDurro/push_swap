SRCS = ${wildcard *.c */*.c}
OBJS = ${SRCS:.c=.o}
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./lbift -I.ft_printf

all: ${NAME}

%.o: %.c
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${SRCS} -o ${NAME}

bonus: all

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re
