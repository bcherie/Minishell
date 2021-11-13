#include "../minishell.h"

static void	counter_comarg(t_tokens *start, t_tokens *end, t_tokens **new)
{
	(*new)->count = -1;
	while (start != NULL && start != end)
	{
		if (start->type == 'c' || start->type == 'a')
			((*new)->count)++;
		start = start->next;
	}
}

void	ft_build_comarg(t_tokens *start, t_tokens *end, t_tokens **new)
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
	(*new)->args[i] = NULL;
}

static void	counter_heredoc(t_tokens *start, t_tokens *end, t_tokens **new)
{
	(*new)->heredoc_n = 0;
	while (start != end)
	{
		if (start->type == 'l')
			((*new)->heredoc_n)++;
		start = start->next;
	}
}

void	ft_build_heredoc(t_tokens *start, t_tokens *end, t_tokens **new)
{
	int	i;

	i = 0;
	(*new)->type = 't';
	if (start == NULL)
		return ;
	counter_heredoc(start, end, new);
	if ((*new)->heredoc_n < 1)
		return ;
	(*new)->heredoc = \
	(char **)malloc(sizeof(char *) * (2 * (*new)->heredoc_n + 1));
	ft_bzero((*new)->heredoc, 2 * (*new)->heredoc_n + 1);
	while (start != NULL && start != end)
	{
		if (start->type == 'L')
		{
			(*new)->heredoc[i] = ft_strdup(&start->type);
			if (start->next != NULL && start->next->type == 'f')
				(*new)->heredoc[i + 1] = start->next->container;
			i += 2;
		}
		start = start->next;
	}
	(*new)->heredoc[i] = NULL;
}
