#include "../minishell.h"

//b - buildins
//e - exec
//f - flags
//p - pipes
//t - text
//r - redirect - right >
//R - redirect - right >>
//l - redirect - left <
//L - redirect - left <<

t_tokens *ft_token_create(void)
{
	t_tokens *token;

	token = NULL;
	token = (t_tokens*)malloc(sizeof(t_tokens));
	if (token == NULL)
		return (NULL);
	token->next = NULL;
	token->prev = NULL;
	token->type = 't';
	token->index = 0;
	token->range = 0;
	token->direction = 'r';
	return (token);
}

t_tokens *ft_token_add(t_all *mass)
{
	t_tokens	*tmp;
	t_tokens	*new;

	tmp = NULL;
	new = ft_token_create();
	if(mass->tokens == NULL)
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

void	ft_token_clean(t_tokens *head)
{
	t_tokens *tmp;

	if (head == NULL)
		return ;
	tmp = head;
	while (tmp->next != NULL)
	{
		head = head->next;
		free(tmp);
		tmp = head;
	}
	free(tmp);
}