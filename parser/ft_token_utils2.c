#include "../minishell.h"

int	simple_startend_check(int start, int end)
{
	if (start < 0 || end < 0 || (end - start) < 0)
		return (0);
	return (1);
}

int	fpf_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_spacekill(char *buf, int start, int end)
{
	int	new_start;

	if (simple_startend_check(start, end) == 0)
		return (-1);
	new_start = start;
	while (buf[new_start] == ' ' && new_start < end)
		new_start++;
	if (buf[new_start] == ' ')
		new_start++;
	return (new_start);
}

int	ft_spacekill_left(char *buf, int start, int end)
{
	int	new_end;

	if (simple_startend_check(start, end) == 0)
		return (-1);
	new_end = end;
	while (buf[new_end] == ' ' && new_end > start)
		new_end--;
	return (new_end);
}
