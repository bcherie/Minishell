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

void	ft_print_env_token(t_tokens *tok)
{
	if (tok->key != NULL)
	{
		printf("%s", tok->key);
		if (tok->value != NULL)
			printf("=%s", tok->value);
		printf("\n");
	}
}
