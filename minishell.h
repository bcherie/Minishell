#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>
#include "structs.h"


size_t	words_count(char const *s, char sp);
void	ft_echo(t_ptr *t_ptr);
// void  ft_echo(t_all mass);
void ft_pwd(void);
void ft_cd(t_ptr *t_ptr);
void echo_n(t_ptr *t_ptr);
void ft_execve(t_all *mass, t_tokens *tmp);
// void ft_export(t_ptr *t_ptr);
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


//BUILDIN_ENV
int			ft_find_char_position(const char *s, char find);
void		ft_add_environment(t_all *mass, char **env);

void		ft_env(t_all *mass);
//// PARSER
void		ft_parser(t_all *mass);
int			ft_spacekill(char *buf, int start, int end);
int			ft_spacekill_left(char *buf, int start, int end);
int			fpf_strchr(const char *s, int c);
int			simple_startend_check(int start, int end);


void		ft_build_command_tokens(t_all *mass);
// Tokens
void		ft_token_name(t_tokens *tmp_token, t_utils *u);
void		ft_token_join_test(t_all *mass, t_utils *u);
t_tokens	*ft_find_last_token(t_tokens *head);

int	ft_dfbuf_count(t_dbuf *dbuf);
void	ft_dfbuf_addchar(t_dbuf *dbuf, char sym);
// Additional Utils
int		init_t_alls(t_all *mass);
void	tmp_int_cleaner(t_all *mass, int mode);
void	global_cleaner(t_all *mass, int mode);
void	ft_print_container(t_all *mass);
#endif
