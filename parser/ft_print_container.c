#include "../minishell.h"

void	ft_print_container(t_all *mass)
{
	t_tokens	*tmp;

	tmp = mass->tokens;
	while (tmp != NULL)
	{
		if (tmp->container != NULL)
			printf("\nDecomposed: IND - (%d): container - (%s): type - (%c)\n", \
			 tmp->index, tmp->container, tmp->type);
		else
			printf("\nDecomposed: IND - (%d): container - NULL: type - (%c)\n", \
			tmp->index, tmp->type);
		tmp = tmp->next;
	}
}
