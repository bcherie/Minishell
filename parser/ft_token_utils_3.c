#include "../minishell.h"

void	ft_token_join_test(t_all *mass, t_utils *u)
{
	char		prev_char;
	t_tokens	*last;

	prev_char = 'x';
	last = ft_find_last_token(mass->tokens);
	u->flag_token_join = 0;
	if (u->iter > 0)
	{
		prev_char = mass->buf[u->n_st - 1];
		if (!fpf_strchr("RrLlp", last->type))
		{
			if (prev_char != ' ')
				u->flag_token_join = 1;
		}
	}
}

void	ft_token_name(t_tokens *tmp_token, t_utils *u)
{
	if (u->flag_find_file == 1)
	{
		u->flag_find_file = 0;
		tmp_token->type = 'f';
	}
	else if (u->flag_find_command == 1)
	{
		u->flag_find_command = 0;
		tmp_token->type = 'c';
	}
	else
		tmp_token->type = 'a';
}

void	ft_token_clean_args(t_tokens **tok)
{
	int	i;
	int	numargs;

	i = 0;
	if (((*tok)->args != NULL) && ((*tok)->args[0] == (*tok)->container))
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
		free(*head);
		*head = tmp;
	}
}
