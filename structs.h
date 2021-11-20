/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 01:11:27 by droro             #+#    #+#             */
/*   Updated: 2021/11/21 01:16:42 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_tokens
{
	struct s_tokens		*next;
	struct s_tokens		*prev;
	char				type;
	int					index;
	int					range;
	char				*container;
	char				**args;
	char				**in_redir;
	char				**out_redir;
	char				*key;
	char				*value;
	int					st;
	int					end;
	int					count;
	int					inp_n;
	int					out_n;
	int					flag_r;
	int					flag_l;
	char				**tmp_out;
	char				**tmp_in;
	int					pipe;
	int					l_pipe;
}					t_tokens;

typedef struct s_dbuf
{
	char			buf[201];
	struct s_dbuf	*next;
	int				full;
}				t_dbuf;

typedef struct s_utils
{
	int			st;
	int			n_st;
	int			end;
	int			n_end;
	int			flag_token_join;
	int			flag_find_command;
	int			flag_find_file;
	int			flag_dollar_on;
	int			i_keyshift;
	int			i_count;
	int			iter;
	int			ct;
}				t_utils;

typedef struct s_all
{
	int					*sub_indx;
	int					*sub_quotes;
	int					count_sym;
	char				*buf;
	char				**tmp;
	t_tokens			*tokens;
	t_tokens			*environment;
	int					number_of_pretokens;
	t_utils				u_mass;
	int					a_count;
	int					flag_error;
	pid_t				pid;
	struct sigaction	siga;
	char				**args;
}				t_all;

#endif
