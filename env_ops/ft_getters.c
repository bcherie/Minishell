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

char	*ft_envops_setval(t_all *mass, char *key, char *val)
{
	t_tokens	*token;

	token = NULL;
	if (key == NULL)
		return (NULL);
	token = ft_is_in_enviroment(mass, key);
	if (token == NULL)
		return (NULL);
	if (token->value != NULL)
		free(token->value);
	if (val == NULL)
	{
		token->value = NULL;
		token->type = ENV_TOK_PARTIAL;
	}
	else
	{
		token->value = ft_strdup(val);
		token->type = ENV_TOK_FULL;
	}
	return (token->value);
}
