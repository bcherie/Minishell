SRCS		= main.c

HEADERS		= struct.h

OBJS		= ${SRCS:.c=.o}

NAME		= minishell

# LIBFT_DIR	= libft/

# LIBFT		= libft.a

# INCLUDES	= -I${LIBFT_DIR}

CC			= gcc

RM			= rm -f

CFLAGS		= -g -Wall -Wextra -Werror

%.o:		%.c ${HEADERS}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${CC} ${CFLAGS} ${OBJS} -lreadline -L/Users/bcherie/.brew/Cellar/readline/8.1/lib/ -I/Users/bcherie/.brew/Cellar/readline/8.1/include -lft -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}


re:			fclean all

.PHONY:		all clean fclean re
