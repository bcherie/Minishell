/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 01:32:54 by droro             #+#    #+#             */
/*   Updated: 2021/11/21 02:41:16 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_buildin(t_all *mass, t_tokens *tok)
{
	int	ret;

	ret	= 1;
	if (ft_strncmp(tok->container, "pwd", 4) == 0)
		ft_pwd(1);
	else if (ft_strncmp(tok->container, "cd", 3) == 0)
		ft_cd(mass, tok);
	else if (ft_strncmp(tok->container, "echo", 5) == 0)
	{
		if ((mass->u_mass.pipe && tok->out_n) || !mass->u_mass.pipe)
			ft_echo(tok);
	}
	else if (ft_strncmp(tok->container, "env", 4) == 0)
		ft_env(mass, tok);
	else if (ft_strncmp(tok->container, "export", 7) == 0)
		ft_export(mass, tok);
	else if (ft_strncmp(tok->container, "exit", 5) == 0)
		ft_exit(mass, tok);
	else if (ft_strncmp(tok->container, "unset", 6) == 0)
		ft_unset(mass, tok);
	else
		ret = 0;
	return (ret);
}

static void ft_run_ops(t_all *mass)
{
	t_tokens	*tmp;
	pid_t		pid;
	pid_t		pid2;
	int			status;
	int			i;

	i = 0;
	mass->u_mass.ct = 0;
	if (mass->flag_error == FLAG_ERROR)
		return ;
	tmp = mass->tokens;
	while (mass->buf[i])
	{
		if (mass->buf[i] == '|')
			mass->u_mass.pipe++;
		i++;
	}
	mass->u_mass.l_pipe = mass->u_mass.pipe;

	while (tmp != NULL)
	{
		if (tmp->inp_n != 0 || tmp->out_n != 0)
		{
			redir_flag_1(tmp);
			ft_check_redirect(tmp);
			if (mass->tokens->flag_l == 2)
			{
				heredok(mass->tokens);
			}
		}
		if (tmp != mass->tokens)
		{
			pid = fork();
			if (pid == 0)
			{
				if (ft_check_buildin(mass, tmp) == 0)
				{
					pid = fork();
					if (pid == 0)
						ft_execve(mass, tmp);
					else
						wait(NULL);
				}
				exit(0);
			}
			else
			{
				waitpid(pid, &status, 0);
			}
		}
		else
		{
			if (ft_check_buildin(mass, tmp) == 0)
			{
				pid2 = fork();
				if (pid2 == 0)
				{
					ft_execve(mass, tmp);
				}
				else
				{
					waitpid(pid2, &status, 0);
				}
			}
		}
		tmp = tmp->next;
		mass->u_mass.ct++;
	}
}

int main(int argc, char **argv, char **env)
{
	t_all	*mass;

	(void)argv;
	(void)argc;
	errno = 0;
	mass = (t_all *)malloc(sizeof(t_all));
	mass->environment = NULL;
	ft_add_environment(mass, env);
	ft_signals_main(mass);
	while (1)
	{
		init_t_alls(mass);
		mass->buf = readline("minishell: ");
		ft_check_EOF(mass);
		if (ft_strlen(mass->buf) > 0)
		{
			add_history(mass->buf);
			ft_parser(mass);
			ft_constructor(mass);
			ft_run_ops(mass);
		}
		global_cleaner(mass, 0);
	}
	return (0);
}
