#include "minishell.h"

static t_tokens *marking_tool(t_tokens *t)
{
	t_tokens	*tmp;
	t_tokens	*last_redir;

	tmp = t;
	t->count = 0;
	last_redir = NULL;
	while (tmp != NULL && ft_strchr("cLlpa", tmp->type) == NULL)
	{
		if (tmp->type == 'r' || tmp->type == 'R')
		{
			t->count++;
			last_redir = tmp;
		}
		tmp = tmp->next;
	}
	t->type = last_redir->type;
	return (tmp);
}

static void	morph_token(t_tokens *start)
{
	t_tokens	*tmp;
	int			i;

	tmp = start;
	i = -1;
	if (start->count > 0)
	{
		start->args = (char **)malloc(sizeof(char *) * (start->count + 2));
		while (++i < start->count)
		{
			if (tmp->next->type == 'r' || tmp->next->type == 'R')
			{
				start->args[i] = NULL;
				tmp = tmp->next;
			}
			else
			{
				start->args[i] = tmp->next->container;
				tmp = tmp->next->next;
			}
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
