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

typedef struct		s_protos
{
	char c;
	struct s_protos *next_node;
	char car**leaf;
	int leaf_n;



}					t_protos;


size_t	words_count(char const *s, char sp);
void  ft_echo(t_all mass, int j);
void ft_pwd(void);
void ft_cd(t_all mass, int j);
void echo_n(t_all mass, int j, int i);

#endif
