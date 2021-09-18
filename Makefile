NAME = minishell
D_PARSE = $(addprefix parser/ft_, $(addsuffix .c, parser token_decompose token_utils token_utils2))
SRCS =	main.c parser.c builtins.c $(D_PARSE)

OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -g

all:		$(NAME)

%.o: %.c
			@$(CC) $(CFLAGS) -c -I./libft/ $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@make -C libft
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libft/libft.a -ltermcap -L/Users/bcherie/.brew/Cellar/readline/8.1/lib/ -I/Users/bcherie/.brew/Cellar/readline/8.1/include -lreadline

run:		$(NAME)
			@./$(NAME)

clean:
			@$(RM) $(OBJS)
			@make clean -C libft

fclean:		clean
			@$(RM) $(NAME)
			@make fclean -C libft

re:			fclean all

.PHONY: 	all run clean fclean re
