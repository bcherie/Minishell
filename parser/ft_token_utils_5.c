/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_utils_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:54:34 by droro             #+#    #+#             */
/*   Updated: 2021/11/16 22:54:34 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pretoken_count(t_all *mass)
{
	int	count;
	int	i;
	int	checker;

	count = 0;
	i = 0;
	checker = 1;
	while (checker == 1)
	{
		if (mass->buf[mass->sub_indx[i]] == '\0' || \
		mass->buf[mass->sub_indx[i + 1]] == '\0')
			checker = 0;
		else
		{
			count++;
			i = i + 2;
		}
	}
	mass->number_of_pretokens = count;
}

void	ft_init_utils_struct(t_utils *u)
{
	u->iter = 0;
	u->flag_find_command = 1;
	u->flag_token_join = 0;
	u->flag_find_file = 0;
	u->flag_dollar_on = 1;
	u->i_keyshift = 0;
	u->i_count = 0;
	u->st = 0;
	u->n_st = 0;
	u->end = 0;
	u->n_end = 0;
}

void	ft_token_join_test(t_all *mass, t_utils *u)
{
	char		prev_char;
	t_tokens	*last;

	prev_char = 'x';
	last = ft_find_last_token(mass->tokens);
	u->flag_token_join = 0;
	if (u->iter > 0)
	{
		prev_char = mass->buf[u->n_st - 1];
		if (!fpf_strchr("RrLlp", last->type))
		{
			if (prev_char != ' ')
				u->flag_token_join = 1;
		}
	}
}

void	ft_token_name(t_tokens *tmp_token, t_utils *u)
{
	if (u->flag_find_file == 1)
	{
		u->flag_find_file = 0;
		tmp_token->type = 'f';
	}
	else if (u->flag_find_command == 1)
	{
		u->flag_find_command = 0;
		tmp_token->type = 'c';
	}
	else
		tmp_token->type = 'a';
}
