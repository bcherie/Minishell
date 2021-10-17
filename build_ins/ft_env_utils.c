#include "../minishell.h"

int	ft_find_char_position(const char *s, char find)
{
	int i;
	int	len;

	i = 0;
	len = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] == find)
			return (i);
		i++;
	}
	return (-1);
}