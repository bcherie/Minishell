NAME = minishell
D_PARSE = $(addprefix parser/ft_, $(addsuffix .c, parser dollar_buf dollar_ops token_decompose token_utils token_utils2))
SRCS =	main.c builtins.c $(D_PARSE)

OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -g

all:		$(NAME)

%.o: %.c
			@$(CC) $(CFLAGS) -c -I./libft/ $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@make -C libft
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libft/libft.a -ltermcap -L/Users/droro/.brew/Cellar/readline/8.1/lib/ -I/Users/droro/.brew/Cellar/readline/8.1/include -lreadline

run:		$(NAME)
			@./$(NAME)

clean:
			@$(RM) $(OBJS)
			@make clean -C libft

fclean:		clean
			@$(RM) $(NAME)
			@make fclean -C libft

re:			fclean all

git:
			git add .
			git commit -m "commit"
			git push

.PHONY: 	all run clean fclean re
