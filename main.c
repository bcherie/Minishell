#include "minishell.h"

static void ft_check_args(t_tokens *tmp, t_all *mass)
{
	//int i = 0;
	while (tmp && tmp->type != '|')
	{
		if(tmp->type == 'a')
		{
			// mass->args[i] = &tmp->container[i];
			// i++;
			mass->a_count++;
		}
		tmp = tmp->next;
	}
	//printf("\nargs: %s", mass->args[0]);
	//printf("\na_count: %d", mass->a_count);
}

// static void check_buildin(t_tokens *tmp, t_all *mass)
// {
// 	if (ft_strncmp(tmp->container, "pwd", 3) == 0)
// 	{
// 		if(ft_strlen(tmp->container) == 3)
// 			ft_pwd();
// 		else
// 			printf("command not found\n");
// 	}
// 	if (ft_strncmp(tmp->container, "cd", 2) == 0)
// 		ft_cd(mass, tmp);
// 	if(ft_strncmp(tmp->container, "echo", 4) == 0)
// 		ft_echo(mass, tmp);
// 	// if(ft_strncmp(tmp->container, "export", 6) == 0)
// 	// 	ft_export();
// 	// if(ft_strncmp(tmp->container, "exeve", 5) == 0)
// 	// 	ft_execve(mass, tmp);

// }

static void ft_command_tockens(t_tokens *tmp, t_all *mass, t_tokens *command)
{
	// int i = 0;
	// int len = 0;
	// int start = 0;
	// int	end = 0;
	command->args = (char **)malloc(sizeof(char *) * mass->a_count + 1);

	char *str = "\0";
	// tmp = mass->tokens;
	// while (tmp->container)
	// {
	// 	len = len + ft_strlen(tmp->container);
	// 	tmp = tmp->next;
	// }
	while (tmp && tmp->type != '|')
	{
		str = ft_strjoin(str, tmp->container);
		//tmp = tmp->next;
		if(tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	// len = ft_strlen(str);
	printf("\nstr: %s", str);
	// printf("\nstr: %d", len);
	// while (tmp && tmp->type != '|')
	// {
	// 	if(tmp->type == 'c')
	// 		command->range = i + 1;
	// 	if(tmp->type == 'a')
	// 		command->args = &tmp->container;
	// 	tmp = tmp->next;
	// }
	//tmp = mass->tokens;
	// printf("\ncontain: %s\n", tmp->container);
	//len = ft_strlen(tmp->container) - ft_strlen(command->container);
}

static void ft_check_comm(t_all *mass)
{
	t_tokens	*tmp;
	t_tokens	*command;
	// int start = 0;
	// int i = 0;
	command = mass->tokens;
	tmp = mass->tokens;
	ft_check_args(tmp, mass);
	command->args = (char **)malloc(sizeof(char *) * mass->a_count + 1);


	// while(tmp)
	// {
	// 	if(tmp->type == 'c')
	// 	{
			ft_command_tockens(tmp, mass, command);
	// 		check_buildin(tmp, mass);
	// 	}
	// 	// else
	// 	// 	break ;
	// 	tmp = tmp->next;
	// }

	// while (tmp && tmp->type != '|')
	// {
	// 	// ft_command_tockens(tmp, mass, command);
	// 	// check_buildin(tmp, mass);
	// 	if (tmp->container[i] == '|' && tmp->next)
	// 		start = i;
	// 	tmp = tmp->next;
	// }
	// printf("\ncontain: %d\n", start);
}

int main (void)
{
	t_all	*mass;

	mass = (t_all*)malloc(sizeof(t_all));
	ft_bzero(mass, sizeof(t_all));

	while (1)
	{
		mass->buf = readline("Minishell: ");
		if (ft_strlen(mass->buf) > 0)
		{
			add_history(mass->buf);
			ft_parser(mass);
			ft_check_comm(mass);
			ft_token_clean(&(mass->tokens));
		}
		if (mass->buf != NULL)
		{
			free(mass->buf);
			mass->buf = NULL;
		}
	}
}
