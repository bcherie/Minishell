#include "struct.h"


int ft_split_commands(t_all mass)
{
	// char *home;
	int j = 0;

	j = words_count(mass.buf, ' ');
	mass.tmp = ft_split(mass.buf, ' ');
	printf("tmp0:%s\n", mass.tmp[0]);
	if(ft_strncmp(mass.tmp[0], "echo", 4) == 0)
		ft_echo(mass, j);
	if (ft_strncmp(mass.tmp[0], "pwd", 3) == 0)
	{
		if(ft_strlen(mass.tmp[0]) == 3)
			ft_pwd();
		else
			printf("command not found\n");
	}
	if (ft_strncmp(mass.tmp[0], "cd", 2) == 0)
		ft_cd(mass, j);

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
		//ft_parser();
		ft_split_commands(mass);
		//free(mass.buf);
	}
	return (0);
}
