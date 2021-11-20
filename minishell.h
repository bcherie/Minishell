/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 01:33:04 by droro             #+#    #+#             */
/*   Updated: 2021/11/21 01:47:34 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define ENV_TOK_FULL 65
# define ENV_TOK_PARTIAL 66
# define ENV_TOK_UNSET 67
# define REP_IDENT 1
# define REP_NOFDIR 2
# define REP_NUMARG 3
# define REP_UNSET_PARAM 4
# define REP_NOFCOMMAND 5
# define REP_SYNTAX_R -1
# define REP_SYNTAX_L -2
# define REP_SYNTAX_P -3
# define REP_SYNTAX_HEREDOC -4
# define FLAG_ERROR -123
# define FLAG_GOOD 0
# include "libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include "structs.h"
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>

size_t		words_count(char const *s, char sp);
void		ft_lstadd_back(t_tokens **list, t_tokens *new);
t_tokens	*ft_lstnew(char *key, char *value);
t_tokens	*ft_lstlast(t_tokens *lst);
t_tokens	*ft_token_create(void);
t_tokens	*ft_token_add(t_all *mass);
void		ft_token_clean(t_tokens **head);
int			ft_token_former(t_all *mass, t_utils *u);
void		ft_token_join_test(t_all *mass, t_utils *u);
int			ft_token_decompose(t_all *mass);
void		ft_token_name(t_tokens *tmp_token, t_utils *u);
void		ft_token_join_test(t_all *mass, t_utils *u);
void		ft_token_clean_args(t_tokens **tok);
void		ft_token_clean_keyval(t_tokens **tok);
void		ft_token_clean_rout(t_tokens **tok);
void		ft_token_clean_rinp(t_tokens **tok);
int			ft_pretoken_check(char *string, int start, int end);
int			ft_token_decompose_nquotes(t_all *mass, t_tokens *tm, t_utils *u);
int			ft_token_decompose_quotes(t_all *mass, t_utils *u);
t_dbuf		*ft_dbuf_create(void);
t_dbuf		*ft_dbuf_add(t_dbuf **head);
int			ft_dbuf_clean(t_dbuf **head);
void		ft_dfbuf_collect(t_dbuf *head, char *newline, int len);
int			ft_checkkeysym(char *buf, t_utils *u);
void		ft_token_keys(char sym, int count, t_tokens *token);
char		*ft_dollar_insert(char *line, t_all *mass);
int			ft_findrange(char *buf, int start, int end);
int			ft_findcommand(char *buf, int start, int end);
int			ft_command_finder(char *buf, int start, int end);
int			ft_space_cleaner(char *buf, int start, int end);
void		ft_pretoken_count(t_all *mass);
int			ft_pretoken_check(char *string, int start, int end);
void		ft_init_utils_struct(t_utils *u);
void		ft_echo(t_tokens *tok);
char		*ft_pwd(int type);
void		ft_cd(t_all *mass, t_tokens *tok);
void		echo_n(t_tokens *tok, int *flag);
void		ft_execve(t_all *mass, t_tokens *tmp);
void		ft_env(t_all *mass, t_tokens *tok);
void		ft_export(t_all *mass, t_tokens *tok);
void		ft_unset(t_all *mass, t_tokens *tok);
void		ft_exit(t_all *mass, t_tokens *tok);
int			ft_find_char_position(const char *s, char find);
int			ft_is_valid_env_token(char *command, char *val);
void		ft_copy_mark_env_token(t_all *mass, const char *env_cont);
t_tokens	*ft_is_in_enviroment(t_all *mass, const char *env_cont);
void		ft_update_environment(t_all *mass, char *command, char *env_cont);
void		ft_add_environment(t_all *mass, char **env);
void		ft_print_env_token(t_tokens *tok, char mode);
int			ft_count_tokens(t_tokens *head);
char		*ft_envops_getval(t_all *mass, char *key);
char		*ft_envops_setval(t_all *mass, char *key, char *val);
int			ft_ms_atoi_checksyms(const char *str);
long long	ft_atolonglong(const char *str);
void		ft_print_report(char *command, char *val, int type);
void		ft_parser(t_all *mass);
int			ft_spacekill(char *buf, int start, int end);
int			ft_spacekill_left(char *buf, int start, int end);
int			fpf_strchr(const char *s, int c);
int			simple_startend_check(int start, int end);
void		ft_build_comarg(t_tokens *start, t_tokens *end, t_tokens **new);
void		ft_build_rout(t_tokens *start, t_tokens *end, t_tokens **new);
void		ft_build_rinp(t_tokens *start, t_tokens *end, t_tokens **new);
void		ft_constructor(t_all *mass);
void		ft_token_simple_clean(t_tokens **head);
int			ft_validate_token_syms(t_all *mass);
void		ft_token_name(t_tokens *tmp_token, t_utils *u);
void		ft_token_join_test(t_all *mass, t_utils *u);
t_tokens	*ft_find_last_token(t_tokens *head);
int			ft_dfbuf_count(t_dbuf *dbuf);
void		ft_dfbuf_addchar(t_dbuf *dbuf, char sym);
int			init_t_alls(t_all *mass);
void		tmp_int_cleaner(t_all *mass, int mode);
void		global_cleaner(t_all *mass, int mode);
void		ft_print_container(t_all *mass);
void		ft_find_exec(t_all *mass, t_tokens *tok);
void		run_current_p(t_tokens *tok, char *current_path);
void		run_exec_folders(t_tokens *tok, char **exec_folders);
void		ft_check_redirect(t_tokens *tok);
int			get_next_line(int fd, char **line);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_strcpy(char *dest, char *src);
void		redir_flag(t_tokens *tok);
void		heredok(t_tokens *tok);
void		rl_replace_line(const char *buffer, int val);
void		ft_signals_main(t_all *mass);

#endif
