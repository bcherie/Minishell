/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:55:50 by droro             #+#    #+#             */
/*   Updated: 2021/11/16 22:55:51 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_find_char_position(const char *s, char find)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] == find)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_copy_mark_env_token(t_all *mass, const char *env_cont)
{
	t_tokens	*env_tmp;
	int			len;
	int			fchar;

	len = ft_strlen(env_cont);
	fchar = ft_find_char_position(env_cont, '=');
	env_tmp = ft_lstnew(NULL, NULL);
	if (fchar == -1)
	{
		env_tmp->key = (char *)malloc(len + 1);
		ft_strlcpy(env_tmp->key, env_cont, len + 1);
		env_tmp->type = ENV_TOK_PARTIAL;
	}
	else
	{
		env_tmp->key = (char *)malloc(fchar + 1);
		ft_strlcpy(env_tmp->key, env_cont, fchar + 1);
		env_tmp->value = (char *)malloc(len - fchar);
		ft_strlcpy(env_tmp->value, &env_cont[fchar + 1], len - fchar);
		env_tmp->type = ENV_TOK_FULL;
	}
	ft_lstadd_back(&mass->environment, env_tmp);
}

t_tokens	*ft_is_in_enviroment(t_all *mass, const char *env_cont)
{
	int			comparelen;
	int			fchar;
	t_tokens	*tmp;

	comparelen = ft_strlen(env_cont);
	tmp = mass->environment;
	fchar = ft_find_char_position(env_cont, '=');
	if (fchar > 0)
		comparelen = fchar;
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->key, env_cont, comparelen) == 0 \
		&& ft_strchr("\0=", (tmp->key)[comparelen]))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_update_environment(t_all *mass, char *command, char *env_cont)
{
	t_tokens	*upd;
	int			fchar;
	int			len;

	if (ft_is_valid_env_token(command, env_cont) == 0)
		return ;
	len = ft_strlen(env_cont);
	fchar = ft_find_char_position(env_cont, '=');
	upd = ft_is_in_enviroment(mass, env_cont);
	if (upd == NULL)
		ft_copy_mark_env_token(mass, env_cont);
	else
	{
		if (fchar > 0)
		{
			if (upd->value != NULL)
				free(upd->value);
			upd->value = (char *)malloc(len - fchar);
			ft_strlcpy(upd->value, &env_cont[fchar + 1], len - fchar);
			upd->type = ENV_TOK_FULL;
		}
		if (upd->type == ENV_TOK_UNSET)
			upd->type = ENV_TOK_PARTIAL;
	}
}
