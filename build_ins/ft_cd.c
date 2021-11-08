#include "../minishell.h"

void		ft_cd(t_all *mass, t_tokens *tok)
{
	int res;
	char *home;
	int i = 0;
	res = 1;

	// printf("key: %s\n", mass->environment->key);
	// printf("value: %s\n", mass->environment->value);
	printf("container: %s\n", mass->environment->container);
	if(tok->count == 0)
	{
		if(ft_strlen(tok->container) == 2)
		{
			home = getenv("HOME");
			chdir(home);
		}
		else
			printf("command not found\n");
	}
	else if (tok->count == 1)
	{
		if(tok->args[0][i] == '~' && ft_strlen(tok->args[i]) == 1)
		{
			home = getenv("HOME");
			chdir(home);
		}
		ft_pwd();
		res = chdir(tok->args[i]);
		printf("res: %d\n", res);
		if(res != 0)
			printf("Не могу перейти к каталогу\n");
	}
	// else
	// 	printf("No such file or directory\n");
}
