#include "../minishell.h"

int	ft_count_tokens(t_tokens *head)
{
	t_tokens	*tmp;
	int			counter;

	counter = 0;
	tmp = head;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		counter++;
	}
	return (counter);
}
