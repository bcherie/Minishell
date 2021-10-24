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

	iter = -1;
	while (++iter < tok->count)
	{
		length = ft_strlen(tok->args[iter]);
		tmp = mass->environment;
		while (tmp != NULL)
		{
			if (ft_strncmp(tok->args[iter], tmp->key, length) == 0)
			{
				tmp->type = ENV_TOK_UNSET;
				if (tmp->value != NULL)
					free(tmp->value);
				tmp->value = NULL;
				break ;
			}
			tmp = tmp->next;
		}
	}
}
