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
	int		range;
	char	direction;
	char	*container;
	char	redir;
	char	pipe;
}					t_tokens;

typedef struct		s_all
{
	char		*buf;
	char		**tmp;
	int			*substr_inds;
	int			count_sym;
	t_tokens	*tokens;
}				t_all;

size_t	words_count(char const *s, char sp);
void  ft_echo(t_all mass, int j);
// void  ft_echo(t_all mass);
void ft_pwd(void);
void ft_cd(t_all mass, int j);
void echo_n(t_all mass, int j, int i);

t_tokens	*ft_token_create(void);
t_tokens *ft_token_add(t_all *mass);
void		ft_token_clean(t_tokens *head);
int			fpf_strchr(const char *s, int c);

int			ft_token_decompose(t_all *mass);
int 		ft_command_finder(char *buf, int start, int end);
int			ft_space_cleaner(char *buf, int start, int end);

void		ft_parser(t_all *mass);

#endif
