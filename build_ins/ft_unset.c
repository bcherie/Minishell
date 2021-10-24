#include "../minishell.h"
/*
TO_DO
	- Написать разметку по ансетам в принт фун-и
	- Написать очистку аргов в токен очистке
	- 
*/
void	ft_unset(t_all *mass, t_tokens *tok)
{
	t_tokens	*tmp;
	int			iter;
	int			length;
	int			num_env;

	tmp = NULL;
	
	iter = -1;
	length = 0;
	num_env = ft_count_tokens(mass->environment);
	while (++iter < num_env)
	{
		length = ft_strlen(tok->args[iter]);
		tmp = mass->environment;
		while (tmp != NULL)
		{
			if (ft_strncmp(tok->args[iter], tmp->key, length) == 0)
			{
				tmp->type = ENV_TOK_UNSET;
				break ;
			}
			tmp = tmp->next;
		}
	}
}
