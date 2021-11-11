#include "../minishell.h"

static t_tokens	*find_edge(t_tokens *start_point)
{
	t_tokens	*end_point;

	end_point = start_point;
	if (end_point != NULL && end_point->type == 'p')
		end_point = end_point->next;
	while (end_point != NULL && end_point->type != 'p')
		end_point = end_point->next;
	return (end_point);
}

static void	merger(t_tokens *start, t_tokens *end, t_tokens **new)
{
	ft_build_comarg(start, end, new);
	ft_build_rinp(start, end, new);
	ft_build_rout(start, end, new);
}

void	ft_constructor(t_all *mass)
{
	t_tokens	*head;
	t_tokens	*new;
	t_tokens	*start;
	t_tokens	*end;

	if (mass->tokens == NULL)
		return ;
	head = mass->tokens;
	start = mass->tokens;
	end = mass->tokens;
	mass->tokens = NULL;
	while (start != NULL)
	{
		end = find_edge(start);
		new = ft_token_add(mass);
		merger(start, end, &new);
		if (end == NULL)
			start = end;
		else
			start = end->next;
	}
	ft_token_simple_clean(&head);
}
