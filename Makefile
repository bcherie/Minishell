SRCS = main.c

NAME = minishell

CC = gcc

OBJS		= ${SRCS:.c=.o}

CFLAGS	= -Wall -Werror -Wextra

%.o:	%.c
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${CC} ${CFLAGS} ${OBJS} -lreadline -L/Users/bcherie/.brew/Cellar/readline/8.1/lib/ -I/Users/bcherie/.brew/Cellar/readline/8.1/include -lft -o ${NAME}

clean:
		rm -f *.o
fclean: clean
		rm -f $(NAME)

re: fclean all
