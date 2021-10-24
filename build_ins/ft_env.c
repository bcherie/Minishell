#include "../minishell.h"

void	ft_add_environment(t_all *mass, char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		ft_copy_mark_env_token(mass, env[i]);
		i++;
	}
	ft_update_environment(mass, NULL, "OLDPWD");
}

void	ft_env(t_all *mass, t_tokens *tok)
{
	t_tokens	*tmp;

	tmp = mass->environment;
	if (tok->count != 0)
		printf("env: %s: No such file or directory\n", tok->args[0]);
	else
	{
		while (tmp != NULL)
		{
			ft_print_env_token(tmp, ENV_TOK_FULL);
			tmp = tmp->next;
		}
	}
}
