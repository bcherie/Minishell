#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct		s_all
{
	char *buf;
	char **tmp;

}				t_all;

size_t	words_count(char const *s, char sp);

#endif
