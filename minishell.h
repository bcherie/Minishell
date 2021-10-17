#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>

// typedef struct s_env
// {
// 	char	**env_args;
// }				t_env;

typedef struct		s_tokens
{
	struct	s_tokens *next;
	struct	s_tokens *prev;
	char	type;
	int		index; 
	int		range; //range command
	char	*container;
	char	**args;
	char	*key;
	char	*value;
	// char	**env_args;
	int		st;
	int		end;
	int		count;
}					t_tokens;

typedef struct		s_ptr
{
	t_tokens		*head;
	t_tokens		*start;
	t_tokens		*end;
	t_tokens		*tmp0;
	t_tokens		*tmp1;
	t_tokens		*command;
	int				count;
	char			**env_args;
	t_tokens		*env;
}					t_ptr;

typedef struct s_env
{
	char *key;
	char *value;

}				t_env;

typedef struct	s_dbuf
{
	char			buf[201];
	struct s_dbuf	*next;
	int				full;
}				t_dbuf;

typedef struct	s_utils
{
	int			st;
	int			n_st;
	int 		end;
	int			n_end;
	int			flag_token_join;
	int			flag_find_command;
	int			flag_find_file;
	int			flag_dollar_on;
	int			i_keyshift;
	int			i_count;
	int			iter;
}				t_utils;

typedef struct	s_all
{
	//PARSER
	int			*sub_indx; // - производится 
	int			*sub_quotes; // - 
	int			count_sym;
	//------------//
	char		*buf;
	char		**tmp;
	t_tokens	*tokens;
	int			number_of_pretokens;
	t_utils		u_mass;
	int			a_count;
	char		**args;
	t_ptr		t_ptrs;
	t_env		*env_st;
}				t_all;



size_t	words_count(char const *s, char sp);
void	ft_echo(t_ptr *t_ptr);
// void  ft_echo(t_all mass);
void ft_pwd(void);
void ft_cd(t_ptr *t_ptr);
void echo_n(t_ptr *t_ptr);
void ft_execve(t_all *mass, t_tokens *tmp);
// void ft_export(t_ptr *t_ptr);
void ft_env(t_ptr *t_ptr, char **env);
// t_env *ft_env_add(t_ptr *t_ptr);
// t_tokens *ft_env_create(void);
void	ft_lstadd_back(t_tokens **list, t_tokens *new);
t_tokens	*ft_lstnew(char *key, char *value);
t_tokens	*ft_lstlast(t_tokens *lst);

t_tokens	*ft_token_create(void);
t_tokens 	*ft_token_add(t_all *mass);
void		ft_token_clean(t_tokens **head);
int			ft_token_former(t_all *mass, t_utils *u);
void		ft_token_join_test(t_all *mass, t_utils *u);
int			ft_token_decompose(t_all *mass);
void		ft_token_name(t_tokens *tmp_token, t_utils *u);
void		ft_token_join_test(t_all *mass, t_utils *u);


t_dbuf		*ft_dbuf_create(void);
t_dbuf		*ft_dbuf_add(t_dbuf **head);
int			ft_dbuf_clean(t_dbuf **head);

char 		*ft_dollar_insert(char *line, t_all *mass);


int 		ft_command_finder(char *buf, int start, int end);
int			ft_space_cleaner(char *buf, int start, int end);
// PARSER
void		ft_parser(t_all *mass);
int			ft_spacekill(char *buf, int start, int end);
int			ft_spacekill_left(char *buf, int start, int end);
int			fpf_strchr(const char *s, int c);
int			simple_startend_check(int start, int end);
// Tokens
void		ft_token_name(t_tokens *tmp_token, t_utils *u);
void		ft_token_join_test(t_all *mass, t_utils *u);
t_tokens	*ft_find_last_token(t_tokens *head);
// Additional Utils
int		init_t_alls(t_all *mass);
void	tmp_int_cleaner(t_all *mass, int mode);
void	global_cleaner(t_all *mass, int mode);
void	ft_print_container(t_all *mass);
#endif
