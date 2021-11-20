/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 01:33:17 by droro             #+#    #+#             */
/*   Updated: 2021/11/21 01:33:17 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/stat.h>

void	run_exec_folders(t_tokens *tok, char **exec_folders)
{
	int			i;
	char		*tmp;
	char		*current_f;
	char		*sym;
	struct stat	buf;

	i = 0;
	sym = "/";
	if (exec_folders != NULL)
	{
		while (exec_folders[i] != NULL)
		{
			current_f = ft_strjoin(exec_folders[i], sym);
			tmp = ft_strjoin(current_f, tok->container);
			free(current_f);
			if (stat(tmp, &buf) == 0)
			{
				execve(tmp, tok->args, NULL);
				free(tmp);
				break ;
			}
			free(tmp);
			i++;
		}
	}

}

void	run_current_p(t_tokens *tok, char *current_path)
{
	char		*tmp;
	char		*tmp2;
	char		*sym;
	struct stat	buf;

	sym = "/";
	tmp = ft_strjoin(current_path, sym);
	tmp2 = ft_strjoin(tmp, tok->container);
	free(tmp);
	if (stat(tmp2, &buf) == 0)
		execve(tmp2, tok->args, NULL);
	free(tmp2);
}

int	count_env(t_all *mass, t_tokens	*env)
{
	t_tokens	*head;
	int			i;

	i = 0;
	head = mass->environment;
	env = mass->environment;
	while (env != NULL)
	{
		if (env->type == ENV_TOK_FULL)
			i++;
		env = env->next;
	}
	env = head;
	return (i);
}

void	write_env(t_all *mass)
{
	char		*v1;
	char		*v2;
	int			j;
	t_tokens	*env;
	int			i;

	j = 0;
	i = 0;
	count_env(mass, env);
	mass->mass_env = (char **) malloc(sizeof(char *) * (i + 1));
	mass->mass_env[i] = NULL;
	while (env != NULL)
	{
		if (env->type == ENV_TOK_FULL)
		{
			v1 = ft_strjoin(env->key, "=");
			v2 = ft_strjoin(v1, env->value);
			free(v1);
			 mass->mass_env[j] = v2;
			j++;
		}
		env = env->next;
	}
}

void	ft_execve(t_all *mass, t_tokens *tok)
{
	char	*path;
	char	*current_path;
	char	**exec_folders;

	write_env(mass);
	path = ft_envops_getval(mass, "PATH");
	exec_folders = ft_split(path, ':');
	current_path = ft_envops_getval(mass, "PWD");
	run_exec_folders(tok, exec_folders);
	run_current_p(tok, current_path);
}
