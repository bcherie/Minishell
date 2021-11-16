#include "minishell.h"

static void ft_check_buildin(t_all *mass, t_tokens *tok)
{
	if (ft_strncmp(tok->container, "pwd", 4) == 0)
		ft_pwd(1);
	else if (ft_strncmp(tok->container, "cd", 3) == 0)
		ft_cd(mass, tok);
	else if (ft_strncmp(tok->container, "echo", 5) == 0)
	{
		if ((tok->pipe && tok->out_n) || !tok->pipe)
			ft_echo(tok);
		else
			return ;
	}
	else if (ft_strncmp(tok->container, "env", 4) == 0)
		ft_env(mass, tok);
	else if (ft_strncmp(tok->container, "export", 7) == 0)
		ft_export(mass, tok);
	else if (ft_strncmp(tok->container, "exit", 5) == 0)
		ft_exit(mass, tok);
	else if (ft_strncmp(tok->container, "unset", 6) == 0)
		ft_unset(mass, tok);
	else if (tok->container != NULL)
	{
		if ((tok->pipe && mass->u_mass.ct == tok->l_pipe) || !tok->pipe)
			ft_execve(mass, tok);
	}
	else
		return ;
}


static void ft_run_ops(t_all *mass)
{
	t_tokens	*tmp;
	pid_t		pid = 0;
	int			i = 0;

	if (mass->flag_error == FLAG_ERROR)
		return ;
	tmp = mass->tokens;
	while (mass->buf[i])
	{
		if (mass->buf[i] == '|')
			tmp->pipe++;
		i++;
	}
	// printf ("pipe %d\n", tmp->pipe);
	mass->u_mass.ct = 0;
	tmp->l_pipe = tmp->pipe;
	while (tmp != NULL)
	{
		if (mass->tokens->out_n != 0 || mass->tokens->inp_n != 0)
		{
			// redir_flag(mass->tokens);
			// if (mass->tokens->flag_l == 2)
			// {
			// 	heredok(mass->tokens);
			// }
			pid = fork();
			if (pid == 0)
			{
				redir_flag(mass->tokens);
				if (mass->tokens->flag_l == 2)
				{
					heredok(mass->tokens);
				}
				ft_check_redirect(mass->tokens);
				ft_check_buildin(mass, tmp);
				exit(EXIT_SUCCESS);
			}
		}
		if (tmp->container != NULL && (!mass->tokens->out_n || mass->tokens->inp_n))
			ft_check_buildin(mass, tmp);
		// }
		mass->u_mass.ct++;
		tmp = tmp->next;
	}
	if (pid != 0)
		wait(NULL);

	// printf("out: %d\n", mass->tokens->out_n);
	// printf("inp: %d\n", mass->tokens->inp_n);
	// printf("count: %d\n", mass->tokens->count);
	// if (mass->tokens->out_n != 0 || mass->tokens->inp_n != 0)
	// {
	// 	ft_check_redirect(mass->tokens);
	// }
	// token - > args - command and arguments
	// 		-> output_ redirect
	// 		-> input_ redirect

	// 		input;
	// 		token->command
	// 		output;
	// token2 ->

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
			//ft_print_container(mass);
			ft_constructor(mass);
			ft_print_container(mass);
			ft_run_ops(mass);
		}
		global_cleaner(mass, 0);
	}
	return (0);
}
