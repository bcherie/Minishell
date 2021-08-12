#include "struct.h"

//if builtins

void ft_split_commands(t_all mass)
{
	char *ptr;
	char *str;
	if (ptr == ft_strnstr(mass.buf, "echo", ft_strlen(mass.buf)))
	{
		str = ft_substr(mass.buf, 5, ft_strlen(mass.buf));
		printf("%s\n", str);
		// work_echo();
	}
}
