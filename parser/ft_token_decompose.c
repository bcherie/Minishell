/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_decompose.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:54:10 by droro             #+#    #+#             */
/*   Updated: 2021/11/16 22:54:11 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	decompose_nquotes_assist(t_all *mass, t_tokens *tm, t_utils *u)
{
	if (u->i_count <= 0)
	{
		if (mass->buf[u->n_st] == '>')
			ft_print_report(NULL, NULL, REP_SYNTAX_R);
		if (mass->buf[u->n_st] == '<')
			ft_print_report(NULL, NULL, REP_SYNTAX_L);
		if (mass->buf[u->n_st] == '|')
			ft_print_report(NULL, NULL, REP_SYNTAX_P);
		return (FLAG_ERROR);
	}
	else
	{
		tm = ft_token_add(mass);
		ft_token_keys(mass->buf[u->n_st], u->i_count, tm);
		if (mass->buf[u->n_st] == '|')
		{
			u->flag_find_command = 1;
			u->flag_find_file = 0;
		}	
		else
			u->flag_find_file = 1;
		u->n_st = u->i_keyshift;
		return (FLAG_GOOD);
	}
}

int	ft_token_decompose_nquotes(t_all *mass, t_tokens *tm, t_utils *u)
{
	if (fpf_strchr("<>|", mass->buf[u->n_st]))
	{
		ft_checkkeysym(mass->buf, u);
		return (decompose_nquotes_assist(mass, tm, u));
	}
	else
	{
		ft_token_join_test(mass, u);
		u->n_end = ft_findrange(mass->buf, u->n_st, u->end);
		u->n_end = ft_findcommand(mass->buf, u->n_st, u->n_end);
		if (ft_token_former(mass, u) == 0)
			return (FLAG_ERROR);
	}
	return (FLAG_GOOD);
}

int	ft_token_decompose_quotes(t_all *mass, t_utils *u)
{
	ft_token_join_test(mass, u);
	if (mass->buf[u->n_st] == 39)
		u->flag_dollar_on = 0;
	u->n_st++;
	u->n_end--;
	if (ft_token_former(mass, u) == 0)
		return (-1);
	u->n_st++;
	u->flag_dollar_on = 1;
	return (1);
}

static void	mini_wheel(t_all *mass, t_tokens *tmp_token, t_utils *u, int *ret)
{
	int	sym_test;

	sym_test = 1;
	while (u->n_st <= u->end && sym_test != FLAG_ERROR)
	{
		if (mass->buf[u->n_st] == ' ')
			u->n_st = ft_spacekill(mass->buf, u->n_st, u->end);
		else
		{
			if (*ret == 2)
				sym_test = ft_token_decompose_nquotes(mass, tmp_token, u);
			else if (*ret == 1)
				sym_test = ft_token_decompose_quotes(mass, u);
		}
	}
	if (sym_test == FLAG_ERROR)
		*ret = FLAG_ERROR;
}

int	ft_token_decompose(t_all *mass)
{
	t_tokens	*tmp_token;
	t_utils		u;
	int			i;
	int			ret;

	i = 0;
	ret = 1;
	tmp_token = NULL;
	ft_pretoken_count(mass);
	ft_init_utils_struct(&u);
	while (ret > 0 && u.iter < mass->number_of_pretokens)
	{
		u.st = mass->sub_indx[i];
		u.end = mass->sub_indx[i + 1];
		u.n_st = u.st;
		u.n_end = u.end;
		ret = ft_pretoken_check(mass->buf, u.st, u.end);
		mini_wheel(mass, tmp_token, &u, &ret);
		i = i + 2;
		u.iter++;
	}
	if (ret == FLAG_ERROR)
		return (FLAG_ERROR);
	return (FLAG_GOOD);
}
