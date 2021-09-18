#include "minishell.h"


// int ft_split_commands(t_all mass)
// {
// 	int j = 0;

// 	j = words_count(mass.buf, ' ');
// 	mass.tmp = ft_split(mass.buf, ' ');
// 	if(ft_strncmp(mass.tmp[0], "echo", 5) == 0)
// 		ft_echo(mass, j);
// 	if (ft_strncmp(mass.tmp[0], "pwd", 4) == 0)
// 	{
// 		if(ft_strlen(mass.tmp[0]) == 3)
// 			ft_pwd();
// 		else
// 			printf("command not found\n");
// 	}
// 	if (ft_strncmp(mass.tmp[0], "cd", 3) == 0)
// 		ft_cd(mass, j);

// 	return (0);
// }

int main (void)
{
	t_all	*mass;

	mass = (t_all*)malloc(sizeof(t_all));
	ft_bzero(mass, sizeof(t_all));

while (1)
	{
		mass->buf = readline("Minishell: ");
		//mass.buf = "e'cho' <file arg";
		//mass->buf = "0'2''56'|'112'45 789' 1'";
		if (ft_strlen(mass->buf) > 0)
		{
			add_history(mass->buf);
			ft_parser(mass);
		}
		if (mass->buf != NULL)
		{
			free(mass->buf);
			mass->buf = NULL;
		}

		// ft_split_commands(mass);
	}
		// mass.buf = "2nd wave";
		// if (ft_strlen(mass.buf) > 0)
		// 	add_history(mass.buf);
		// ft_parser(&mass);
	return (0);
}
