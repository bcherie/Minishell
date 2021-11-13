#include "../minishell.h"

void	ft_token_clean_args(t_tokens **tok)
{
	int	i;
	int	numargs;

	i = 0;
	if ((*tok)->args == NULL)
		return ;
	if ((*tok)->args[0] == (*tok)->container)
		numargs = (*tok)->count + 2;
	else
		numargs = (*tok)->count + 1;
	if ((*tok)->args == NULL)
		return ;
	while (i < numargs)
	{
		if ((*tok)->args[i] != NULL)
		{
			free((*tok)->args[i]);
			(*tok)->args[i] = NULL;
		}
		i++;
	}
	free((*tok)->args);
	(*tok)->args = NULL;
	(*tok)->container = NULL;
}

void	ft_token_clean_keyval(t_tokens **tok)
{
	if ((*tok)->key != NULL)
	{
		free((*tok)->key);
		(*tok)->key = NULL;
	}
	if ((*tok)->value != NULL)
	{
		free((*tok)->value);
		(*tok)->value = NULL;
	}
}

void	ft_token_clean_rinp(t_tokens **tok)
{
	int	i;
	int	num;

	i = -1;
	num = 0;
	if ((*tok)->in_redir == NULL)
		return ;
	num = 2 * (*tok)->inp_n + 1;
	while (++i < num)
	{
		if ((*tok)->in_redir[i] != NULL)
		{
			free((*tok)->in_redir[i]);
			(*tok)->in_redir[i] = NULL;
		}
	}
	free((*tok)->in_redir);
	(*tok)->in_redir = NULL;
}

void	ft_token_clean_rout(t_tokens **tok)
{
	int	i;
	int	num;

	i = -1;
	num = 0;
	if ((*tok)->out_redir == NULL)
		return ;
	num = 2 * (*tok)->out_n + 1;
	while (++i < num)
	{
		if ((*tok)->out_redir[i] != NULL)
		{
			free((*tok)->out_redir[i]);
			(*tok)->out_redir[i] = NULL;
		}
	}
	free((*tok)->out_redir);
	(*tok)->out_redir = NULL;
}

void	ft_token_clean(t_tokens **head)
{
	t_tokens	*tmp;

	if (!head || !(*head))
		return ;
	while (*head)
	{
		tmp = (*head)->next;
		if ((*head)->container != NULL)
		{
			if ((*head)->args != NULL)
			{
				if ((*head)->container != (*head)->args[0])
					free((*head)->container);
			}
			else
				free((*head)->container);
		}
		ft_token_clean_args(head);
		ft_token_clean_keyval(head);
		ft_token_clean_heredoc(head);
		ft_token_clean_rout(head);
		ft_token_clean_rinp(head);
		free(*head);
		*head = tmp;
	}
}
