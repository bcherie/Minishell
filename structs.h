#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_tokens
{
	struct	s_tokens *next;
	struct	s_tokens *prev;
	char	type;
	int		index;
	int		range; //range command
	char	*container;
	//		FOR FINAL TOKEN;
	char	**args;
	char	**in_redir;
	char	**out_redir;
	char	**heredoc;
	//		ENV
	char	*key;
	char	*value;
	// char	**env_args;
	int		st;
	int		end;
	// Счетчики аргументы, инпуты, аупуты
	int		count;
	int		inp_n;
	int		out_n;
	int		heredoc_n;
}					t_tokens;


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

	int			*sub_indx;
	int			*sub_quotes;
	int			count_sym;
	char		*buf;

	char		**tmp;
	t_tokens	*tokens;
	t_tokens	*environment;
	int			number_of_pretokens;
	t_utils		u_mass;
	int			a_count;
	int			flag_error;
	pid_t		pid;
	char		**args;
}				t_all;


#endif