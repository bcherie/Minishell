#include "minishell.h"

static t_tokens *marking_tool(t_tokens *t)
{
	t_tokens	*tmp;

	tmp = t;
	t->count = -1;
	while (tmp != NULL && ft_strchr("cLlpa", tmp->type) == NULL)
	{
		t->count++;
		tmp = tmp->next;
	}
	return (tmp);
}

static void	morph_token(t_tokens *start)
{
	t_tokens	*tmp;
	int			i;

	tmp = start;
	i = 0;
	if (start->count > 0)
	{
		start->args = (char **)malloc(sizeof(char *) * (start->count + 2));
		while (i < start->count + 1)
		{
			start->args[i] = tmp->container;
			i++;
			tmp = tmp->next;
		}
		start->args[i] = NULL;
	}
}

static void	delete_unused_tokens(t_tokens **start, t_tokens **end)
{
	t_tokens	*tmp;
	t_tokens	*stop_flag;

	tmp = NULL;
	if (start == NULL)
		return ;
	tmp = *start;
	if (end == NULL)
		stop_flag = NULL;
	else
		stop_flag = *end;
	while (tmp != stop_flag)
	{
		tmp = (*start)->next;
		free(*start);
		*start = tmp;
	}
}

void	ft_build_redirect_tokens(t_all *mass)
{
	t_tokens	*tmp_end;
	t_tokens	*tmp_start;
	t_tokens	*tmp;
	int			i;

	tmp_start = mass->tokens;
	tmp_end = mass->tokens;
	tmp = mass->tokens->next;
	i = 0;
	while (tmp_start != NULL)
	{
		if (tmp_start->type == 'r' || tmp_start->type == 'R')
		{
			tmp_end = marking_tool(tmp_start);
			morph_token(tmp_start);
			delete_unused_tokens(&(tmp_start->next), &tmp_end);
			if (tmp_end != NULL)
				tmp_end->prev = tmp_start;
		}
		tmp_start->index = i;
		i++;
		tmp_start = tmp_start->next;	
	}
}
