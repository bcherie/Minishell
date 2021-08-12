#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft/libft.h"

typedef struct		s_all
{
	char *buf;

}				t_all;

int ft_split_commands(t_all mass);

#endif
