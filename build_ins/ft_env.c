#include "../minishell.h"

void	ft_add_environment(t_all *mass, char **env)
{
	t_tokens	*env_tmp;
	int			i;
	int			len;
	int			fchar;

	fchar = 0;
	len = 0;
	env_tmp = NULL;
	i = 0;
	while (env[i] != NULL)
	{
		len = ft_strlen(env[i]);
		fchar = ft_find_char_position(env[i], '=');
		env_tmp = ft_lstnew(NULL, NULL);
		if (fchar == -1)
		{	
			env_tmp->key = (char *)malloc(len + 1);
			ft_strlcpy(env_tmp->key, env[i], len + 1);
		}
		else
		{
			env_tmp->key = (char *)malloc(fchar);
			ft_strlcpy(env_tmp->key, env[i], fchar + 1);
			env_tmp->value = (char *)malloc(len - fchar);
			ft_strlcpy(env_tmp->value, &env[i][fchar + 1], len - fchar + 1);
		}
		ft_lstadd_back(&mass->environment, env_tmp);
		i++;
	}
	// printf("key: %s\n", mass->environment->key);
	// printf("value: %s\n", mass->environment->value);
}

void	ft_env(t_all *mass)
{
	t_tokens	*tmp;

	tmp = mass->environment;
	while (tmp != NULL)
	{
		if (mass->environment->key != NULL)
		{
			printf("%s", mass->environment->key);
			if (mass->environment->value != NULL)
			{
				printf("=%s", mass->environment->value);
			}
			printf("\n");
		}
		tmp = tmp->next;
	}
}