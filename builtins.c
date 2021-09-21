#include "minishell.h"

// void ft_execve(t_all *mass, t_tokens *tmp)
// {
// 	char *path;
// 	char **path_arg;
// 	int i;
// use stat function here!!!!!!!!!!!!!

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

void ft_export(t_ptr *t_ptr)
{
	

}

void echo_n(t_ptr *t_ptr)
{
	int i;
	int j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;

	if(t_ptr->count == 1)
	{
		printf("");
		return ;
	}
	// if(t_ptr->command->args[0][0] != '-' && t_ptr->command->args[0][1] != 'n')
	// 	flag = 0;
	// else
	// {
	// 	j = 1;
	// 	while (t_ptr->command->args[0][j] == 'n')
	// 		j++;
	// 	if (t_ptr->command->args[0][j] != '\0')
	// 	{
	// 		i = 0;
	// 		flag = 0;
	// 	}
	// 	else
	// 	{
	// 		i = 1;
	// 		flag = 1;
	// 	}
	// }
	// while (t_ptr->command->args[i] != NULL)
	// {
	// 	write(1, t_ptr->command->args[i], ft_strlen(t_ptr->command->args[i]));
	// 	i++;
	// }
	// if (!flag)
	// 	write(1, "\n", 1);
	if(t_ptr->count > 1)
	{
		// len = ft_strlen(&tmp->container[1]);
		// while (t_ptr->command->args[i])
		// {
			// if(t_ptr->command->args[0][0] != '-' && t_ptr->command->args[0][1] != 'n')
			// {
			// 	write(1, t_ptr->command->args++, ft_strlen(*t_ptr->command->args));
			// 	write(1, "\n", 1);
			// }
			// else
			// {
			// 	// j = j + 1;
			// 	while (t_ptr->command->args[0][j] == 'n')
			// 		j++;
			// 	if (t_ptr->command->args[0][j])
			// 	{
			// 		write(1, t_ptr->command->args++, ft_strlen(*t_ptr->command->args));
			// 		write(1, "\n", 1);
			// 	}
			// 	else
			// 	{
			// 		t_ptr->command->args++;
			// 		write(1, t_ptr->command->args++, ft_strlen(*t_ptr->command->args));
			// 	}
			// }
			// i++;
		// }

		if(t_ptr->command->args[0][0] == '-' && t_ptr->command->args[0][1] == 'n')
		{
			// flag = 1;
			while (t_ptr->command->args[0][j] == 'n')
				j++;
			// if(t_ptr->command->args[0][j] != '\0')
			// {
			// j = 1;
			while(t_ptr->command->args[i + 1][0] == '-' && t_ptr->command->args[i + 1][1] == 'n')
			{
				i++;
			}
			// }

		}
		// else
		// 	flag = 0;
		// if(flag == 0)
		// {
		// 	write(1, t_ptr->command->args++, ft_strlen(*t_ptr->command->args));
		// 	write(1, "\n", 1);
		// }
		// else
		// {
		t_ptr->command->args++;
		// write(1, t_ptr->command->args++, ft_strlen(*t_ptr->command->args));
		while (t_ptr->command->args[i])
		{
			write(1, t_ptr->command->args[i], ft_strlen(t_ptr->command->args[i]));
			if(t_ptr->command->args[i + 1] != NULL)
				write(1, " ", 1);
			i++;
		}
		// }
	}
}

void	ft_echo(t_ptr *t_ptr)
{
	int i;
	int j;
	int flag;
	//прописать тут флаг -n
	flag = 0;
	i = 0;
	j = 0;
	if(t_ptr->count == 0)
	{
		if (ft_strlen(t_ptr->command->container) == 4)
			printf("\n");
		else
			printf("command not found\n");
	}
	else if(t_ptr->count >= 1)
	{
		while (t_ptr->command->args[i])
		{
			if (!(ft_strnstr(t_ptr->command->args[i], "-n", ft_strlen(t_ptr->command->args[i]))))
			{
				flag = 0;
				write(1, t_ptr->command->args[i], ft_strlen(t_ptr->command->args[i]));
				if(t_ptr->command->args[i + 1] != NULL)
					write(1, " ", 1);
			}
			else
			{
				flag = 1;
		 		echo_n(t_ptr);
				break ;
			}
			i++;
		}
		if(flag != 1)
			printf("\n");
	}
}

void ft_pwd(void)
{
	char *path;
	char *buffer = NULL;

	path = getcwd(buffer, sizeof(buffer));
	printf("%s\n", path);
}

void ft_cd(t_ptr *t_ptr)
{
	int res;
	char *home;
	int i = 0;
	res = 1;

	if(t_ptr->count == 0)
	{
		if(ft_strlen(t_ptr->command->container) == 2)
		{
			home = getenv("HOME");
			chdir(home);
		}
		else
			printf("command not found\n");
	}
	else if (t_ptr->count == 1)
	{
		if(t_ptr->command->args[0][i] == '~' && ft_strlen(t_ptr->command->args[i]) == 1)
		{
			home = getenv("HOME");
			chdir(home);
		}
		ft_pwd();
		res = chdir(t_ptr->command->args[i]);
		printf("res: %d\n", res);
		if(res != 0)
			printf("Не могу перейти к каталогу\n");
	}
	// else
	// 	printf("No such file or directory\n");
}
