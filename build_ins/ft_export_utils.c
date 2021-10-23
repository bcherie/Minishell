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

void	ft_print_env_token(t_tokens *tok, char mode)
{
	if (mode == ENV_TOK_FULL)
	{
		if (tok->type == mode)
			printf("%s=%s\n", tok->key, tok->value);
	}
	else if (mode == ENV_TOK_PARTIAL)
	{
		if (tok->value != NULL)
			printf("declare -x %s=\"%s\"\n", tok->key, tok->value);
		else
			printf("declare -x %s=\"\"\n", tok->key);
	}
	else
		return ;
}
