#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include "struct.h"

char *path;

void ft_pwd(char *str)
{
	//char *path;
	//прописать с getcwd(), так как getwd() запрещена
	path = getcwd(str, 1000);
	printf("%s\n", path);
}

void ft_cd(char *str)
{
	//chdir - сменить текущий каталог
	//Возвращается  0  в случае  успеха  и -1 в противном случае с установлением errno.
	int res;

	ft_pwd(str);
	res = chdir(path);
	printf("res: %d\n", res);
	if(res != 0)
		printf("Не могу перейти к каталогу %s\n", path);
	else
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
	// while (str[i] != '\0')
	// {
	// 	if (str[i] == ' ')
	// 		i++;
		if(ft_strncmp(mass.buf, "echo", 4) == 0)
		{
			str = ft_substr(mass.buf, 4, ft_strlen(mass.buf));
			printf("subsrt: %s\n", str);
			// work_echo();
		}
		//тут не будет аргументов, нужно нафиг убрать стрнстр и сабстр
		if (ft_strncmp(mass.buf, "pwd", 3) == 0)
		{
			str = ft_substr(mass.buf, 3, ft_strlen(mass.buf));
			ft_pwd(str);
		}
			//printf("pwd: %s\n", str);
		if (ft_strncmp(mass.buf, "cd", 2) == 0)
		{
			str = ft_substr(mass.buf, 2, ft_strlen(mass.buf));
			//printf("cd: %s\n", str);
			ft_cd(str);
		}
	// 	i++;
	// }

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
		//free(mass.buf);
	}
	return (0);
}
