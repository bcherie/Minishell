#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>
#include "struct.h"


char *path;

void ft_pwd(void)
{
	char *buffer = NULL;
	path = getcwd(buffer, sizeof(buffer));
	printf("%s\n", path);
}

void ft_cd(char *str)
{
	//chdir - сменить текущий каталог
	//Возвращается  0  в случае  успеха  и -1 в противном случае с установлением errno.
	// просто cd - переходит на уровень учетки
	int res;

	char *path_s;
	ft_pwd();
	// printf("cd_str: %s\n", str);
	path_s = ft_strjoin (path, str);
	res = chdir(path_s);
	printf("res: %d\n", res);
	if(res != 0)
		printf("Не могу перейти к каталогу %s\n", path_s);
	else
		printf("%s\n", path_s);
}

int ft_split_commands(t_all mass)
{
	char *str = NULL;
	// char *tmp = NULL;
	// // // char *str_sym;
	// // // str_sym = ">, >>";
	// // // char q = 34;
	int i = 0;
	int spaces = 0;
	int len = 0;
	// char *buffer = NULL;
	char *home;
	if(ft_strncmp(mass.buf, "echo", 4) == 0)
	{
		while (mass.buf[i])
		{
			if(mass.buf[i] == ' ')
				spaces++;
			i++;
		}
		len = ft_strlen(mass.buf) - spaces;
		str = ft_substr(mass.buf, 5, len);
		printf("%s\n", str);
	}
	//тут не будет аргументов, нужно нафиг убрать стрнстр и сабстр
	if (ft_strncmp(mass.buf, "pwd", 3) == 0)
	{
		// str = ft_strdup(mass.buf);
		// printf("%s\n", mass.buf);
		// printf("%c\n", mass.buf[3]);
		if (mass.buf[3] == ' ' || mass.buf[3] == '\0')
			ft_pwd();
		else
			printf("command not found\n");
	}
		//printf("pwd: %s\n", str);
	if (ft_strncmp(mass.buf, "cd", 2) == 0)
	{
		while (mass.buf[i])
		{
			if(mass.buf[i] == ' ')
				spaces++;
			i++;
		}
		if(ft_strlen(mass.buf) == 2)
		{
			home = getenv("HOME");
			chdir(home);
		}
		else
		{
			printf("sp: %d\n", spaces);
			len = ft_strlen(mass.buf) - spaces;
			str = ft_substr(mass.buf, 3, len);
			str = ft_strjoin("/", str);
			printf("cd_str:%s\n", str);
			ft_cd(str);
		}
	}
	// 	i++;
	// }

	return (0);
}

// void ft_parser(t_all mass)
// {
// 	int i = 0;

// 	while (mass.buf != '\0')
// 	{
// 		if(mass.buf[i] == ' ')

// 	}
// }


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
