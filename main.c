#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "struct.h"

int ft_split_commands(t_all mass)
{
	char *str;
	// char *str_sym;
	// str_sym = ">, >>";
	// char q = 34;
	if (ft_strnstr(mass.buf, "echo ", ft_strlen(mass.buf)))
	{
		str = ft_substr(mass.buf, 5, ft_strlen(mass.buf));
		printf("subsrt: %s\n", str);
		// work_echo();
	}
	return (0);
}

int main (void)
{
	t_all mass;
	mass.buf = NULL;
	//init(mass);

	while (1)
	{
		mass.buf = readline("Minishell: ");
		if (ft_strlen(mass.buf) > 0)
			add_history(mass.buf);
		ft_split_commands(mass);
		free(mass.buf);
	}
	return (0);
}
