#include "minishell.h"

t_tokens	*ft_lstnew(char *key, char *value)
{
	t_tokens *new;

	new = (t_tokens*)malloc(sizeof(t_tokens));
	if (!new)
		return (NULL);
	if (key != NULL)
		new->key = key;
	if (value != NULL)
		new->value = value;
	new->next = NULL;
	new->type = '0';
	new->index = -1;
	return (new);
}

void	ft_lstadd_back(t_tokens **list, t_tokens *new)
{
	t_tokens	*last;

	last = ft_lstlast(*list);
	if (!new)
		return ;
	else if (!*list)
	{
		*list = new;
		return ;
	}
	last->next = new;
}

t_tokens	*ft_lstlast(t_tokens *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
