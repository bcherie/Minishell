#include "../minishell.h"

static t_tokens *find_pre_min(t_tokens *head)
{
	t_tokens	*tmp;

	tmp = head;
	while (tmp != NULL && tmp->index != -1)
		tmp = tmp->next;
	return (tmp);
}

static int	ft_compare_keys(const char *f, const char *s)
{
	int	len_f;
	int len_s;
	int	out_strcmp;

	out_strcmp = 0;
	len_f = ft_strlen(f);
	len_s = ft_strlen(s);
	if (len_f <= len_s)
		return (ft_strncmp(f, s, len_f + 1));
	return (ft_strncmp(f, s, len_s + 1));
}

static void	ft_enumerate_tokens(t_tokens *head)
{
	int			iter;
	int			count;
	t_tokens	*tmp;
	t_tokens	*cur_min;

	iter = 0;
	count = ft_count_tokens(head);
	while (iter < count)
	{
		cur_min = find_pre_min(head);
		tmp = cur_min->next;
		while (tmp != NULL)
		{
			if (tmp->index == -1)
			{
				if (ft_compare_keys(cur_min->key, tmp->key) > 0)
					cur_min = tmp;
			}
			tmp = tmp->next;
		}
		cur_min->index = iter;
		iter++;
	}
}

void	ft_export(t_all *mass, t_tokens *tok)
{
	t_tokens	*tmp;
	int			iter;
	int			count;

	tmp = mass->environment;
	if (tmp == NULL)
		return ;
	iter = 0;
	if (tok->count > 0)
		ft_add_environment(mass, tok->args);
	count = ft_count_tokens(tmp);
	ft_enumerate_tokens(tmp);
	while (iter < count)
	{
		tmp = mass->environment;
		while (tmp != NULL && tmp->index != iter)
			tmp = tmp->next;
		ft_print_env_token(tmp);
		iter++;
	}
}

/* TO_DO

- Сделать расширенную разметку типов: не все печатаются в энвехе, что-то печатается только в экспорте
- Сделать обработку ввода на валидный и невалидный аргумент
- Рассмотреть кейс с вэлью с началом с ' '
- В цдэхе сделать обновление pwd/oldpwd
- Вынести копирование env перед основным циклом программы



*/