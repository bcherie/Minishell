SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
	  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
	  ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c \
	  ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	  ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strstr.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
		ft_lstiter.c ft_lstmap.c

NAME = libft.a

OBJECT = ${SRC:.c=.o}

OBJECT_BONUS = ${BONUS:.c=.o}

FLAGS = -Wall -Werror -Wextra

CC = gcc

.c.o:  
	${CC} ${FLAGS} -g -c $< -o ${<:.c=.o} 

all: ${NAME}

$(NAME): $(OBJECT)
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)

bonus: $(OBJECT) $(OBJECT_BONUS)
	ar rc $(NAME) $(OBJECT) $(OBJECT_BONUS)
	ranlib $(NAME)

clean: 
	rm -f ${OBJECT} ${OBJECT_BONUS}

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
