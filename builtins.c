#include "minishell.h"

void echo_n(t_all mass, int j, int i)
{
	j = j - 2;
	//printf("j: %d\n", j);
	while (mass.tmp[i + 2])
	{
		printf("%s ", mass.tmp[i + 2]);
		i++;
	}
}

void	ft_echo(t_all mass, int j)
{
	int i;
	//прописать тут флаг -n

	i = 0;
	if(j == 1)
	{
		if (ft_strlen(mass.tmp[0]) == 4)
			printf("\n");
		else
			printf("command not found\n");
	}
	else if(j > 1)
	{
		if (!(ft_strnstr(mass.tmp[1], "-n", ft_strlen(mass.tmp[1]))))
		{
			j = j - 1;
			//printf("j: %d\n", j);
			while (mass.tmp[i + 1])
			{
				//printf("%s ", mass.tmp[i + 1]);
				i++;
			}
			printf("\n");
		}
		else
			echo_n(mass, j , i);
	}
}
// void	ft_echo(t_all *mass)
// {
// 	int i;
// 	//прописать тут флаг -n

// 	i = 0;
// 	mass->tockens.type
// }

void ft_pwd(void)
{
	char *path;
	char *buffer = NULL;

	path = getcwd(buffer, sizeof(buffer));
	printf("%s\n", path);
}

void ft_cd(t_all *mass, t_tokens *tmp)
{
	int res;
	char *home;
	int i = 0;
	res = 1;

	if(mass->a_count == 0)
	{
		if(ft_strlen(tmp->container) == 2)
		{
			home = getenv("HOME");
			chdir(home);
		}
		else
			printf("command not found\n");
	}
	else if (mass->a_count == 1)
	{
		ft_pwd();
		res = chdir(mass->args[i]);
		printf("res: %d\n", res);
		if(res != 0)
			printf("Не могу перейти к каталогу\n");
	}
	// else
	// 	printf("No such file or directory\n");
}
