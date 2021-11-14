NAME = minishell
D_PARSE = $(addprefix parser/ft_, $(addsuffix .c, print_container parser parser_ops dollar_buf dollar_ops dollar_ops_2 token_decompose token_utils token_utils_2 token_utils_3 token_utils_4 token_utils_5))
D_BUILD_INS = $(addprefix build_ins/ft_, $(addsuffix .c, cd export export_utils echo pwd env env_utils unset exit atolonglong validations print_report))
D_ENVOPS = $(addprefix env_ops/ft_, $(addsuffix .c, getters))
D_CONSTRUCT = $(addprefix constructor/ft_, $(addsuffix .c, build_command_tokens build_redirect_tokens constructor))
SRCS =	main.c main_utils.c buildin_utils.c execve.c redirect.c $(D_PARSE) $(D_BUILD_INS) $(D_ENVOPS) $(D_CONSTRUCT)

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
