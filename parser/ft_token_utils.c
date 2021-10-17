#include "../minishell.h"

t_tokens	*ft_token_create(void)
{
	t_tokens	*token;

	token = NULL;
	token = (t_tokens *)malloc(sizeof(t_tokens));
	if (token == NULL)
		return (NULL);
	token->next = NULL;
	token->prev = NULL;
	token->container = NULL;
	token->type = 'x';
	token->index = 0;
	return (token);
}

t_tokens	*ft_token_add(t_all *mass)
{
	t_tokens	*tmp;
	t_tokens	*new;

	tmp = NULL;
	new = ft_token_create();
	if (mass->tokens == NULL)
	{
		mass->tokens = new;
		mass->tokens->index = 0;
	}
	else
	{
		tmp = mass->tokens;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
		new->index = tmp->index + 1;
	}
	return (new);
}

void	ft_token_clean(t_tokens **head)
{
	t_tokens	*tmp;

	if (!head || !(*head))
		return ;
	tmp = NULL;
	while (*head)
	{
		tmp = (*head)->next;
		free((*head)->container);
		(*head)->container = NULL;
		free(*head);
		*head = tmp;
	}
}

t_tokens	*ft_find_last_token(t_tokens *head)
{
	if (head == NULL)
		return (NULL);
	else
	{
		while (head->next != NULL)
			head = head->next;
		return (head);
	}
}

int	ft_token_former(t_all *mass, t_utils *u)
{
	t_tokens	*tmp_token;

	tmp_token = ft_find_last_token(mass->tokens);
	if (u->flag_token_join == 0)
	{
		tmp_token = ft_token_add(mass);
		tmp_token->container = \
		ft_substr(mass->buf, u->n_st, u->n_end - u->n_st + 1);
		if (u->flag_dollar_on == 1)
			tmp_token->container = ft_dollar_insert(tmp_token->container, mass);
		ft_token_name(tmp_token, u);
	}
	else
	{
		mass->tmp[2] = mass->tmp[1];
		mass->tmp[1] = ft_substr(mass->buf, u->n_st, u->n_end - u->n_st + 1);
		if (u->flag_dollar_on == 1)
			mass->tmp[1] = ft_dollar_insert(mass->tmp[1], mass);
		tmp_token->container = ft_strjoin(tmp_token->container, mass->tmp[1]);
		tmp_int_cleaner(mass, 0);
	}
	u->n_st = u->n_end + 1;
	return (1);
}
