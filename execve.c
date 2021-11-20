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
	int     i;
	char    *tmp;
	char    *current_f;
	char    *sym = "/";
	struct stat buf;
	int		res;
	i = 0;
	res = 0;
	while (exec_folders[i] != NULL)
	{
		current_f = ft_strjoin(exec_folders[i], sym);
		tmp = ft_strjoin(current_f, tok->container);
		// printf("P (%d) - (%s)\n", i, tmp);
		if (stat(tmp, &buf) == 0)
		{
			execve(tmp, tok->args, NULL);
			tok->container = NULL;
			break ;
			// if ((res = execve(tmp, tok->args, NULL)) == -1)
			// 	exit(EACCES);
		}
		// else
		//     printf("I'm so sorry\n");
		free(tmp);
		// else
		//     printf("I'm so sorry\n");
		i++;
	}

}

void	run_current_p(t_tokens *tok, char *current_path)
{
    char	*tmp;
    char	*tmp2;
    char	*sym = "/";
    struct	stat buf;

	tmp = ft_strjoin(current_path, sym);
	tmp2 = ft_strjoin(tmp, tok->container);
	// printf("x - (%s)\n", tmp2);
	if (stat(tmp2, &buf) == 0)
	{
		// printf("XXXX\n");
		execve(tmp2, tok->args, NULL);
		tok->container = NULL;
		// exit(EXIT_SUCCESS);
	}
}

void    ft_execve(t_all *mass, t_tokens *tok)
{
    char    *path;
    char    *current_path;
    char    **exec_folders;
    char    **mass_env;
	char	*v1;
	char	*v2;
    int     i;
	int		j;

	i = 0;
	j = 0;
    pid_t pid;

    t_tokens *env;
	t_tokens *head;

	head = mass->environment;
    env = mass->environment;
	while (env != NULL)
	{
		if (env->type == ENV_TOK_FULL)
			i++;
		env = env->next;
	}
	env = head;
    mass_env = (char **) malloc(sizeof(char *) * (i + 1));
	mass_env[i] = NULL;
    while (env != NULL)
    {
		if (env->type == ENV_TOK_FULL)
		{
			v1 = ft_strjoin(env->key, "=");
			v2 = ft_strjoin(v1, env->value);
			mass_env[j] = v2;
			free(v1);
			j++;
		}
		env = env->next;
    }

    path = ft_envops_getval(mass, "PATH");
    exec_folders = ft_split(path, ':');
    current_path = ft_envops_getval(mass, "PWD");
    pid = fork();
	if (pid == 0)
	{
		if (current_path)
		{
			run_current_p(tok, current_path);
		}
		if (path)
		{
			run_exec_folders(tok, exec_folders);
		}
		else
		{
			printf("Command hasn't found\n");
		}
	}
	if (pid != 0)
		wait(NULL);

}
