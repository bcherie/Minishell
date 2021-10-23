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
	//		ENV
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
	char		*buf;
	//------------//
	
	char		**tmp;
	t_tokens	*tokens;
	t_tokens	*environment;
	int			number_of_pretokens;
	t_utils		u_mass;
	int			a_count;
	char		**args;
}				t_all;


#endif