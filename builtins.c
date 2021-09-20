#include "minishell.h"

// void ft_execve(t_all *mass, t_tokens *tmp)
// {
// 	char *path;
// 	char **path_arg;
// 	int i;

// 	i = 0;
// 	path = getenv("PATH");
// 	path_arg = ft_split(path, ':');
// 	//mass->str = path_arg[i];
// 	//printf("\npath:%s\n", mass->str);
// 	//ft_cd(mass->str);
// 	i = chdir("/usr/bin");
// 	if (i == 0)
// 		printf("sucsess");
// 	// printf("\npath:%s\n", tmp);
// 	// printf("\npath1:%s, path2:%s\n", path_arg[0], path_arg[1]);
// 	//ret = execve("/bin/ls", NULL, NULL);
// }

void echo_n(t_all *mass, t_tokens *tmp)
{
	// int len;
	int i;
	int j;

	// len = 0;
	i = 0;
	j = 0;
	//printf("j: %d\n", j);
	// echo -n
	if(mass->a_count == 1)
		printf("");
	if(mass->a_count > 1)
	{
		// len = ft_strlen(&tmp->container[1]);
		while (tmp->container[i])
		{
			if(mass->args[0][i] != '-' && tmp->container[i + 1] != 'n')
			{
				write(1, &mass->args[j], ft_strlen(mass->args[j]));
				write(1, "\n", 1);
			}
			else
				write(1, &mass->args[j], ft_strlen(mass->args[j]));
			i++;
		}
	}
}

void	ft_echo(t_all *mass, t_tokens *tmp)
{
	int i;
	int j;
	//прописать тут флаг -n

	i = 0;
	j = 0;
	if(mass->a_count == 0)
	{
		if (ft_strlen(tmp->container) == 4)
			printf("\n");
		else
			printf("command not found\n");
	}
	else if(mass->a_count >= 1)
	{
		while (mass->args[j])
		{
			if (!(ft_strnstr(mass->args[i], "-n", ft_strlen(mass->args[i]))))
			{
				write(1, mass->args[i], ft_strlen(mass->args[i]));
				printf("\n");
			}
			else
				echo_n(mass, tmp);
			j++;
		}
	}
}

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
		if(mass->args[0][i] == '~' && ft_strlen(mass->args[i]) == 1)
		{
			home = getenv("HOME");
			chdir(home);
		}
		ft_pwd();
		res = chdir(mass->args[i]);
		printf("res: %d\n", res);
		if(res != 0)
			printf("Не могу перейти к каталогу\n");
	}
	// else
	// 	printf("No such file or directory\n");
}
