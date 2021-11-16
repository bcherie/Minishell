/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:53:09 by droro             #+#    #+#             */
/*   Updated: 2021/11/16 22:54:54 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	simple_check(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '$')
		{
			if (line[++i] == '\0')
				break ;
			if (ft_isalnum(line[i]) || line[i] == '#' || line[i] == '?')
				return (1);
		}
		i++;
	}
	return (0);
}

static void	ft_dol_a_case(char *line, t_all *mass, t_utils *t, t_dbuf *head)
{
	char	*substring;

	t->iter++;
	t->i_keyshift = t->iter;
	while (ft_isalnum(line[t->i_keyshift]))
		(t->i_keyshift)++;
	if (t->iter == t->i_keyshift)
		mass->tmp[0] = ft_substr(line, t->iter, t->i_keyshift - t->iter + 1);
	else
		mass->tmp[0] = ft_substr(line, t->iter, t->i_keyshift - t->iter);
	t->iter = t->i_keyshift;
	substring = ft_envops_getval(mass, mass->tmp[0]);
	tmp_int_cleaner(mass, 0);
	if (substring != NULL)
	{
		while (substring[t->i_count] != '\0')
			ft_dfbuf_addchar(head, substring[(t->i_count)++]);
	}
}

static void	ft_sym_case(char *line, t_utils *t, t_dbuf *head)
{
	char	*subline;
	char	*orig;

	(t->iter)++;
	subline = NULL;
	if (line[t->iter] == '#' || line[t->iter] == '?')
		subline = ft_itoa(errno);
	else
		subline = ft_strdup("minishell");
	orig = subline;
	while (*subline != '\0')
	{
		ft_dfbuf_addchar(head, *subline);
		subline++;
	}
	free(orig);
	subline = NULL;
	orig = NULL;
}

static void	wheel(char *line, t_all *mass, t_utils *t, t_dbuf *head)
{
	while (line[t->iter] != '\0')
	{
		if (line[t->iter] != '$')
			ft_dfbuf_addchar(head, line[t->iter]);
		else
		{
			if (ft_isalpha(line[t->iter + 1]))
			{
				ft_dol_a_case(line, mass, t, head);
				continue ;
			}
			else if (fpf_strchr("0#?", line[t->iter + 1]))
				ft_sym_case(line, t, head);
			else if (ft_isdigit(line[t->iter + 1]))
				t->iter++;
		}
		t->iter++;
	}
}

char	*ft_dollar_insert(char *line, t_all *mass)
{
	char	*newline;
	t_dbuf	*head;
	t_utils	t;

	newline = NULL;
	if (simple_check(line) == 0)
		return (line);
	ft_bzero(&t, sizeof(t_utils));
	head = ft_dbuf_create();
	wheel(line, mass, &t, head);
	t.i_count = ft_dfbuf_count(head);
	newline = (char *)malloc(t.i_count + 1);
	newline[t.i_count] = '\0';
	ft_dfbuf_collect(head, newline, t.i_count);
	ft_dbuf_clean(&head);
	free(line);
	line = NULL;
	return (newline);
}
