#include "minishell.h"

static void ft_check_buildin(t_all *mass, t_tokens *tok)
{
	if (ft_strncmp(tok->container, "pwd", 4) == 0)
		ft_pwd();
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
	else if(tok->container != NULL)
		ft_execve(mass, tok);
	else
		return ;
}

static void ft_run_ops(t_all *mass)
{
	t_tokens	*tmp;

	tmp = mass->tokens;
	// Fork commands!!!

	while (tmp != NULL)
	{
		if (tmp->type == 'c')
		{
			ft_check_buildin(mass, tmp);
			// break ;
		}
		else if (tmp->type == 'r' && tmp->container != NULL)
			ft_check_redirect(tmp);
		tmp = tmp->next;
	}
}

int main (int argc, char **argv, char **env)
{
	t_all	*mass;

	(void)argv;
	(void)argc;
	mass = (t_all*)malloc(sizeof(t_all));
	ft_add_environment(mass, env);
	while (1)
	{
		init_t_alls(mass);
		mass->buf = readline("minishell: ");
		if (ft_strlen(mass->buf) > 0)
		{
			add_history(mass->buf);
			ft_parser(mass);
			//redirect
			ft_build_command_tokens(mass);
			//ft_redirect(mass);
			ft_print_container(mass);
			ft_run_ops(mass);
		}
		global_cleaner(mass, 0);
	}
	return (0);
}
