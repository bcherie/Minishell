#include "minishell.h"

static void	counter_comarg(t_tokens *start, t_tokens *end, t_tokens **new)
{
	(*new)->count = -1;
	while (start != end)
	{
		if (start->type == 'c' || start->type == 'a')
			((*new)->count)++;
		start = start->next;
	}
}

void	ft_build_command_tokens(t_tokens *start, t_tokens *end, t_tokens **new)
{
	int	i;

	i = 0;
	(*new)->type = 't';
	if (start == NULL)
		return ;
	counter_comarg(start, end, new);
	if ((*new)->count < 0)
		return ;
	(*new)->args = (char **)malloc(sizeof(char *) * ((*new)->count + 2));
	ft_bzero((*new)->args, (*new)->count + 2);
	while (start != NULL && start != end)
	{
		if (start->type == 'c' || start->type == 'a')
		{
			if (start->type == 'c')
				(*new)->container = start->container;
			(*new)->args[i] = start->container;
			i++;
		}
		start = start->next;
	}
}
