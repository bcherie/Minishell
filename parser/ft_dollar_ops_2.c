#include "../minishell.h"

void	ft_dfbuf_collect(t_dbuf *head, char *newline, int len)
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
