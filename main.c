#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include "struct.h"

void ft_pwd(char *str)
{
	char *path;
	//прописать с getcwd(), так как getwd() запрещена
	path = getwd(str);
	printf("%s\n", path);
}

int ft_split_commands(t_all mass)
{
	char *str = NULL;
	// char *tmp = NULL;
	// // // char *str_sym;
	// // // str_sym = ">, >>";
	// // // char q = 34;
	// int i = 0;
	// while (mass.buf[i] != ' ')
	// {
	// 	if (i == '"')
	// 		continue ;
	// 	else
	// 		tmp[i] = mass.buf[i];
	// 	i++;
	// 	//кавычки перескочить и записать буквы в строку
	// 	//str = "echo";
	// }
	// printf("tmp: %s\n", tmp);
	if (ft_strnstr(mass.buf, "echo ", ft_strlen(mass.buf)))
	{
		str = ft_substr(mass.buf, 5, ft_strlen(mass.buf));
		printf("subsrt: %s\n", str);
		// work_echo();
	}
	//тут не будет аргументов, нужно нафиг убрать стрнстр и сабстр
	if (ft_strnstr(mass.buf, "pwd", ft_strlen(mass.buf)))
	{
		str = ft_substr(mass.buf, 3, ft_strlen(mass.buf));
		ft_pwd(str);
	}
		//printf("pwd: %s\n", str);
	if (ft_strnstr(mass.buf, "cd", ft_strlen(mass.buf)))
	{
		str = ft_substr(mass.buf, 2, ft_strlen(mass.buf));
		ft_pwd(str);
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
