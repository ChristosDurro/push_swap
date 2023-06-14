SRCS = push_swap.c check_commands.c check_params.c list_utils.c place_commands.c \
		placing_functions.c  push.c reverse_rotate.c \
		rotate.c sort_utils.c sort.c stack_node_utils.c stack_utils.c \
		swap.c
BONUS_SRCS = checker.c check_commands.c check_params.c list_utils.c place_commands.c \
		placing_functions.c  push.c reverse_rotate.c \
		rotate.c sort_utils.c sort.c stack_node_utils.c stack_utils.c \
		swap.c

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror 

all: ${NAME}

%.o: %.c
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${CFLAGS}  ${SRCS} lib/libftprintf.a lib/libft.a -o ${NAME}

bonus: all
	${CC} ${CFLAGS} ${BONUS_SRCS} lib/libftprintf.a lib/libft.a -o ${BONUS_NAME}

clean:
	rm -f ${OBJS} ${BONUS_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re
