#include "minishell.h"

static void ft_check_buildin(t_all *mass, t_tokens *tok)
{
	if (ft_strncmp(tok->container, "pwd", 4) == 0)
		ft_pwd();
	else if (ft_strncmp(tok->container, "cd", 3) == 0)
		ft_cd(tok);
	else if (ft_strncmp(tok->container, "echo", 5) == 0)
		ft_echo(tok);
	else if (ft_strncmp(tok->container, "env", 4) == 0)
		ft_env(mass, tok);
	else if(ft_strncmp(tok->container, "export", 7) == 0)
		ft_export(mass, tok);
	// if(ft_strncmp(tmp->container, "exeve", 5) == 0)
	// 	ft_execve(mass, tmp);
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
			break ;
		}
		tmp = tmp->next;
	}
}

int main (int argc, char **argv, char **env)
{
	t_all	*mass;
	(void)argv;
	(void)argc;
	mass = (t_all*)malloc(sizeof(t_all));
	while (1)
	{
		init_t_alls(mass);
		mass->buf = readline("Minishell: ");
		if (ft_strlen(mass->buf) > 0)
		{
			add_history(mass->buf);
			ft_add_environment(mass, env);
			ft_parser(mass);
			ft_build_command_tokens(mass);
			//ft_print_container(mass);
			ft_run_ops(mass);
			ft_token_clean(&(mass->tokens));
			//ft_token_clean(&(mass->environment));
		}
		global_cleaner(mass, 0);
	}
	global_cleaner(mass, 1);
	return (0);
}
