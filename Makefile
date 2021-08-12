SRCS = main.c

NAME = minishell

CC = gcc

OBJS		= ${SRCS:.c=.o}

CFLAGS	= -Wall -Werror -Wextra

%.o:	%.c
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${CC} ${CFLAGS} ${OBJS} -lreadline -L/Users/bcherie/.brew/Cellar/readline/8.1/lib/ -I/Users/bcherie/.brew/Cellar/readline/8.1/include -lft -o ${NAME}

${Libft/}${Libft/libft.a}: ${Libft/}
			${MAKE} -C ${Libft/}

clean:
		rm -f *.o
		$(MAKE) clean -C $(Libft/)
fclean: clean
		rm -f $(NAME)

re: fclean all
