#include "../minishell.h"

t_dbuf *ft_dbuf_create(void)
{
	t_dbuf *dbuf;

	dbuf = NULL;
	dbuf = (t_dbuf*)malloc(sizeof(t_dbuf));
	if (dbuf == NULL)
		return (NULL);
	dbuf->next = NULL;
	dbuf->full = 0;
	ft_bzero(dbuf->buf, 201);
	return (dbuf);
}

t_dbuf *ft_dbuf_add(t_dbuf **head)
{
	t_dbuf	*tmp;
	t_dbuf	*new;

	tmp = NULL;
	new = ft_dbuf_create();
	if(*head == NULL)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

int	ft_dbuf_clean(t_dbuf **head)
{
	t_dbuf	*tmp;

	if (!head || !(*head))
		return (0);
	tmp = NULL;
	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = NULL;
		*head = tmp;
	}
	return (1);
}