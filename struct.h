#ifndef MINISHELL_H
# define MINISHELL_H

#include "Libft/libft.h"

typedef struct		s_all
{
	char *buf;

}				t_all;

void ft_split_commands(t_all mass);

#endif
