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

// t_tokens *ft_env_create(void)
// {
// 	t_tokens *env;

// 	env = NULL;
// 	env = (t_tokens*)malloc(sizeof(t_tokens));
// 	if (env == NULL)
// 		return (NULL);
// 	env->next = NULL;
// 	env->prev = NULL;
// 	env->container = NULL;
// 	env->type = 'x';
// 	env->index = 0;
// 	env->key = NULL;
// 	env->value = NULL;
// 	return (env);
// }

// t_tokens *ft_env_add(t_tokens *envir, char **env)
// {
// 	t_tokens	*tmp;
// 	t_tokens	*new;

// 	tmp = NULL;
// 	new = ft_env_create();
// 	if(t_ptr->env == NULL)
// 	{
// 		t_ptr->env = new;
// 		t_ptr->env->index = 0;
// 	}
// 	else
// 	{
// 		tmp = t_ptr->env;
// 		while (tmp->next != NULL)
// 			tmp = tmp->next;
// 		tmp->next = new;
// 		new->prev = tmp;
// 		new->index = tmp->index + 1;
// 	}
// 	return (new);
// }
