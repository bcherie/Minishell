#include "../minishell.h"

static int	simple_check(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '$')
		{
			if (line[++i] == '\0')
				break ;
			if (ft_isalnum(line[i]) || line[i] == '#' || line[i] == '?')
				return (1);
		}
		i++;
	}
	return (0);
}

static void	ft_dfbuf_collect(t_dbuf *head, char *newline, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len && head != NULL)
	{
		newline[i] = head->buf[j];
		i++;
		j++;
		if (j == 200)
		{
			head = head->next;
			j = 0;
		}
	}
}
// static void ft_substring(t_all *m, t_dbuf **head, t_utils *t, char **subst)
// {
// 	*subst = getenv(m->tmp[0]);
// 	tmp_int_cleaner(m, 0);
// 	if (*subst != NULL)
// 	{
// 		while (*subst[t->i_count] != '\0')
// 			ft_dfbuf_addchar(*head, *subst[(t->i_count)++]);
// 	}
// }

static void	ft_alpha(t_all *mass, t_utils *t, char *line)
{
	t->iter++;
	t->i_keyshift = t->iter;
	while (ft_isalnum(line[t->i_keyshift]))
		(t->i_keyshift)++;
	if (t->iter == t->i_keyshift)
		mass->tmp[0] = ft_substr(line, t->iter, t->i_keyshift - t->iter + 1);
	else
		mass->tmp[0] = ft_substr(line, t->iter, t->i_keyshift - t->iter);
	t->iter = t->i_keyshift;
}

char	*ft_dollar_insert(char *line, t_all *mass)
{
	char	*newline;
	char	*subline;
	char	*substring;
	t_dbuf	*head;
	t_utils	t;

	newline = NULL;
	subline = NULL;
	substring = NULL;
	if (simple_check(line) == 0)
		return (line);
	ft_bzero(&t, sizeof(t_utils));
	head = ft_dbuf_create();
	while (line[t.iter] != '\0')
	{
		if (line[t.iter] != '$')
			ft_dfbuf_addchar(head, line[t.iter]);
		else
		{
			if (ft_isalpha(line[t.iter + 1]))
			{
				ft_alpha(mass, &t, line);
				substring = getenv(mass->tmp[0]);
				tmp_int_cleaner(mass, 0);
				if (substring != NULL)
				{
					while (substring[t.i_count] != '\0')
						ft_dfbuf_addchar(head, substring[(t.i_count)++]);
				}
				continue ;
			}
			else if (fpf_strchr("0#?", line[t.iter + 1]))
			{
				t.iter++;
				if (line[t.iter] == '#' || line[t.iter] == '?')
					ft_dfbuf_addchar(head, '0');
				else
				{
					subline = "minishell";
					while (*subline != '\0')
					{
						ft_dfbuf_addchar(head, *subline);
						subline++;
					}
				}
			}
			else if (ft_isdigit(line[t.iter + 1]))
				t.iter++;
		}
		t.iter++;
	}
	t.i_count = ft_dfbuf_count(head);
	newline = (char *)malloc(t.i_count + 1);
	newline[t.i_count] = '\0';
	ft_dfbuf_collect(head, newline, t.i_count);
	ft_dbuf_clean(&head);
	free(line);
	line = NULL;
	return (newline);
}
