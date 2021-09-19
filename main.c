#include "minishell.h"

// static void ft_check_args(t_tokens *tmp, t_all *mass)
// {
// 	int i = 0;
// 	while (tmp && tmp->type != '|')
// 	{
// 		if(tmp->type == 'a')
// 		{
// 			mass->args[i] = &tmp->container[i];
// 			i++;
// 			mass->a_count++;
// 		}
// 		tmp = tmp->next;
// 	}
// 	//printf("\nargs: %s", mass->args[0]);
// 	//printf("\na_count: %d", mass->a_count);
// }

static void check_buildin(t_tokens *tmp, t_all *mass)
{
	if (ft_strncmp(tmp->container, "pwd", 3) == 0)
	{
		if(ft_strlen(tmp->container) == 3)
			ft_pwd();
		else
			printf("command not found\n");
	}
	if (ft_strncmp(tmp->container, "cd", 2) == 0)
		ft_cd(mass, tmp);
	if(ft_strncmp(tmp->container, "echo", 4) == 0)
		ft_echo(mass, tmp);
	// if(ft_strncmp(tmp->container, "export", 6) == 0)
	// 	ft_export();
	// if(ft_strncmp(tmp->container, "exeve", 5) == 0)
	// 	ft_execve(mass, tmp);

// }

// static void ft_check_comm(t_all *mass)
// {
// 	t_tokens *tmp;

// 	tmp = mass->tokens;
// 	ft_check_args(tmp, mass);
// 	while(tmp)
// 	{
// 		if(tmp->type == 'c')
// 			check_buildin(tmp, mass);
// 		else
// 			break ;
// 		tmp = tmp->next;
// 	}
// }


int main (void)
{
	t_all	*mass;

	mass = (t_all*)malloc(sizeof(t_all));


	while (1)
	{
		ft_bzero(mass, sizeof(t_all));
		//mass->buf = ft_strdup("ec'ho' |cho cho");
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
		free(mass->buf);
		// if (mass->buf != NULL)
		// {
		// 	free(mass->buf);
		// 	mass->buf = NULL;
		// }
		// if (mass->tmp != NULL)
		// {
		// 	free(mass->tmp);
		// 	mass->tmp = NULL;
		// }
	}
}
