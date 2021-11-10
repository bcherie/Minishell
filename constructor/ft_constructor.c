#include "minishell.h"

static t_tokens*	find_edge(t_tokens *start_point)
{
	t_tokens	*end_point;

	end_point = start_point;
	if (end_point != NULL && end_point->type == 'p')
		end_point = end_point->next;
	while (end_point != NULL && end_point->type != 'p')
		end_point = end_point->next;
	return (end_point);
}

void	ft_constructor(t_all *mass)
{
	t_tokens	*head;
	t_tokens	*new;
	t_tokens	*start_point;
	t_tokens	*end_point;

	if (mass->tokens == NULL)
		return ;
	head = mass->tokens;
	start_point = mass->tokens;
	end_point = mass->tokens;
	mass->tokens = NULL;
	while (start_point != NULL)
	{
		end_point = find_edge(start_point);
		new = ft_token_add(mass);
		start_point = end_point;
	}

}