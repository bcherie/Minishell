#include "../minishell.h"

char	*ft_envops_getval(t_all *mass, char *key)
{
	t_tokens	*token;

	token = NULL;
	if (key == NULL)
		return (NULL);
	token = ft_is_in_enviroment(mass, key);
	if (token == NULL)
		return (NULL);
	return (token->value);
}
