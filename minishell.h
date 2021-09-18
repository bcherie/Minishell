#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct		s_tokens
{
	struct	s_tokens *next;
	struct	s_tokens *prev;
	char	type;
	int		index;
	char	*container;
}					t_tokens;

typedef struct	s_utils
{
	int			st;
	int			n_st;
	int 		end;
	int			n_end;
	int			c_end;
	int			flag_token_join;
	int			flag_find_command;
	int			i_keyshift;
	int			i_count;
	int			iter;
}				t_utils;

typedef struct	s_all
{
	char		*buf;
	char		**tmp;
	int			*sub_indx;
	int			count_sym;
	t_tokens	*tokens;
	int			number_of_pretokens;
	int			a_count;
	char		**args;
}				t_all;



size_t	words_count(char const *s, char sp);
void	ft_echo(t_all *mass, t_tokens *tmp);
// void  ft_echo(t_all mass);
void ft_pwd(void);
void ft_cd(t_all *mass, t_tokens *tmp);
void echo_n(t_all *mass, t_tokens *tmp);
void ft_execve(t_all *mass, t_tokens *tmp);

t_tokens	*ft_token_create(void);
t_tokens *ft_token_add(t_all *mass);
void		ft_token_clean(t_tokens *head);
int			fpf_strchr(const char *s, int c);

int			ft_token_decompose(t_all *mass);
int 		ft_command_finder(char *buf, int start, int end);
int			ft_space_cleaner(char *buf, int start, int end);

void		ft_parser(t_all *mass);

#endif
