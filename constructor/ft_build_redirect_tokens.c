#include "../minishell.h"

static void	counter_rout(t_tokens *start, t_tokens *end, t_tokens **new)
{
	(*new)->out_n = 0;
	while (start != end)
	{
		if (start->type == 'r' || start->type == 'R')
			((*new)->out_n)++;
		start = start->next;
	}
}

void	ft_build_rout(t_tokens *start, t_tokens *end, t_tokens **new)
{
	int	i;

	i = 0;
	(*new)->type = 't';
	if (start == NULL)
		return ;
	counter_rout(start, end, new);
	if ((*new)->out_n < 1)
		return ;
	(*new)->out_redir = \
	(char **)malloc(sizeof(char *) * (2 * (*new)->out_n + 1));
	ft_bzero((*new)->out_redir, 2 * (*new)->out_n + 1);
	while (start != NULL && start != end)
	{
		if (start->type == 'r' || start->type == 'R')
		{
			(*new)->out_redir[i] = ft_strdup(&start->type);
			if (start->next != NULL && start->next->type == 'f')
				(*new)->out_redir[i + 1] = start->next->container;
			i += 2;
		}
		start = start->next;
	}
	(*new)->out_redir[i] = NULL;
}

static void	counter_rinp(t_tokens *start, t_tokens *end, t_tokens **new)
{
	(*new)->inp_n = 0;
	while (start != end)
	{
		if (start->type == 'l' || start->type == 'L')
			((*new)->inp_n)++;
		start = start->next;
	}
}

void	ft_build_rinp(t_tokens *start, t_tokens *end, t_tokens **new)
{
	int	i;

	i = 0;
	(*new)->type = 't';
	if (start == NULL)
		return ;
	counter_rinp(start, end, new);
	if ((*new)->inp_n < 1)
		return ;
	(*new)->in_redir = \
	(char **)malloc(sizeof(char *) * (2 * (*new)->inp_n + 1));
	ft_bzero((*new)->in_redir, 2 * (*new)->inp_n + 1);
	while (start != NULL && start != end)
	{
		if (start->type == 'l' || start->type == 'L')
		{
			(*new)->in_redir[i] = ft_strdup(&start->type);
			if (start->next != NULL && start->next->type == 'f')
				(*new)->in_redir[i + 1] = start->next->container;
			i += 2;
		}
		start = start->next;
	}
	(*new)->in_redir[i] = NULL;
}
