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
// 	//ret = execve("/bin/ls"(commad[0]), command, env);
// }

// void ft_export(t_ptr *t_ptr)
// {
// 	int i;
// 	// int j;
// 	// int res;
// 	// char *alph;
// 	// char *alph_up;
// 	// int	z;

// 	i = 0;
// 	//t_env *env;



// 	while (t_ptr->env_args[i])
// 	{
// 		ft_env_add(t_ptr);
// 		// t_ptr->env->container = t_ptr->env_args[i];
// 		// t_ptr->env = t_ptr->env->next;
// 		i++;
// 	}
// 	printf("\n%s\n", t_ptr->env->container);

// 	// alph = "abcdefghijklmnopqrstuvwxyz";
// 	// alph_up = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// 	// i = 0;
// 	// j = 0;
// 	// z = 0;
// 	// if(t_ptr->count == 0)
// 	// {
// 	// 	//отсортировать енв в алфавитном порядке
// 	// 	while (t_ptr->env_args[i])
// 	// 	{
// 	// 		if(ft_strncmp(&t_ptr->env_args[0][0], alph[z], 66) == 0 || ft_strncmp(&t_ptr->env_args[0][0], alph_up[z], 66) == 0)
// 	// 			// res = ft_strncmp(&t_ptr->env_args[i][j + 1], &t_ptr->env_args[i + 1][j + 1], 10);
// 	// 			{
// 	// 				write(1, &t_ptr->env_args[i], ft_strlen(&t_ptr->env_args[i][j + 1]));
// 	// 		 		write(1, "\n", 1);
// 	// 			}
// 			// else
// 			// {
// 			// 	if(res > 0)
// 			// 	{
// 			// 		write(1, &t_ptr->env_args[i], ft_strlen(&t_ptr->env_args[i][j + 1]));
// 			// 		write(1, "\n", 1);
// 			// 		write(1, &t_ptr->env_args[i + 1], ft_strlen(&t_ptr->env_args[i + 1][j + 1]));
// 			// 		write(1, "\n", 1);
// 			// 	}
// 			// 	else
// 			// 	{
// 			// 		write(1, &t_ptr->env_args[i + 1], ft_strlen(&t_ptr->env_args[i + 1][j + 1]));
// 			// 		write(1, "\n", 1);
// 			// 		write(1, &t_ptr->env_args[i], ft_strlen(&t_ptr->env_args[i + 1][j + 1]));
// 			// 		write(1, "\n", 1);
// 			// 	}
// 			// }
// 	// 		i++;
// 	// 	}
// 	// }


// }
void ft_env(t_ptr *t_ptr, char **env)
{
	int i;
	int j;
	int l;

	i = 0;
	j = 0;
	l = 0;

	while (env[l] != NULL)
		l++;
	t_ptr->env_args = (char **)malloc(sizeof(char *) * l);
	while (env[i] != NULL)
	{
		t_ptr->env_args[i] = env[i];
		i++;
	}
	while (t_ptr->env_args[j])
	{
		write(1, t_ptr->env_args[j], ft_strlen(t_ptr->env_args[j]));
		write(1, "\n", 1);
		j++;
	}
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
	if(t_ptr->count > 1)
	{

		if(t_ptr->command->args[0][0] == '-' && t_ptr->command->args[0][1] == 'n')
		{
			// flag = 1;
			while (t_ptr->command->args[0][j] == 'n')
				j++;
			while(t_ptr->command->args[i + 1][0] == '-' && t_ptr->command->args[i + 1][1] == 'n')
			{
				i++;
			}
		}
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
		while (i < t_ptr->command->count)
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
