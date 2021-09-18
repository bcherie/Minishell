#include "../minishell.h"

int			fpf_strchr(const char *s, int c)
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

