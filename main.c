/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 01:32:54 by droro             #+#    #+#             */
/*   Updated: 2021/11/21 01:32:55 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int ft_check_buildin(t_all *mass, t_tokens *tok)
{
	int	ret;

	ret = 1;
	if (ft_strncmp(tok->container, "pwd", 4) == 0)
		ft_pwd(1);
	else if (ft_strncmp(tok->container, "cd", 3) == 0)
		ft_cd(mass, tok);
	else if (ft_strncmp(tok->container, "echo", 5) == 0)
			ft_echo(tok);
	else if (ft_strncmp(tok->container, "env", 4) == 0)
		ft_env(mass, tok);
	else if (ft_strncmp(tok->container, "export", 7) == 0)
		ft_export(mass, tok);
	else if (ft_strncmp(tok->container, "exit", 5) == 0)
		ft_exit(mass, tok);
	else if (ft_strncmp(tok->container, "unset", 6) == 0)
		ft_unset(mass, tok);
	else if (tok->container != NULL)
		ft_execve(mass, tok);
	else
		ret = 0;
	return (ret);
}


static void ft_run_ops(t_all *mass)
{
	t_tokens	*tmp;
	pid_t		pid;
	int			i;
	int			status;

	status = 0;
	i = 0;
	if (mass->flag_error == FLAG_ERROR)
		return ;
	tmp = mass->tokens;
	while (mass->buf[i])
	{
		if (mass->buf[i] == '|')
			tmp->pipe++;
		i++;
	}
	mass->u_mass.ct = 0;
	tmp->l_pipe = tmp->pipe;
	while (tmp != NULL)
	{
		if (mass->tokens->out_n != 0 || mass->tokens->inp_n != 0)
		{
			pid = fork();
			if (pid == 0)
			{
				redir_flag(mass->tokens);
				if (mass->tokens->flag_l == 2)
					heredok(mass->tokens);
				ft_check_redirect(mass->tokens);
				ft_check_buildin(mass, tmp);
				exit(EXIT_SUCCESS);
			}
			else
				waitpid(pid, &status, 0);
		}
		if (tmp->container != NULL && (!mass->tokens->out_n || mass->tokens->inp_n))
			ft_check_buildin(mass, tmp);
		mass->u_mass.ct++;
		tmp = tmp->next;
	}
}


void	ft_check_EOF(t_all *mass)
{
	if (mass->buf == NULL)
	{	
		write(1, "exit\n", 5);
		global_cleaner(mass, 1);
		exit(0);
	}
}

int main (int argc, char **argv, char **env)
{
	t_all	*mass;

	(void)argv;
	(void)argc;
	errno = 0;
	mass = (t_all*)malloc(sizeof(t_all));
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
