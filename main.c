#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "struct.h"

// void ft_split_commands(t_all mass)
// {
// 	char *ptr;
// 	char *str;
// 	if (ptr == ft_strnstr(mass.buf, "echo", ft_strlen(mass.buf)))
// 	{
// 		str = ft_substr(mass.buf, 5, ft_strlen(mass.buf));
// 		printf("%s\n", str);
// 		// work_echo();
// 	}
// }

int main (int argc, char **argv, char **env)
{
	t_all mass;
	mass.buf = NULL;
	//init(mass);
	while (1)
	{
		mass.buf = readline("Minishell: ");
		if (ft_strlen(mass.buf) > 0)
			add_history(mass.buf);
		// ft_split_commands(mass);
		printf("print:%s\n", mass.buf);
	}
	// printf("%s\n", mass.buf);
	return (0);
}
