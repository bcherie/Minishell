#include "struct.h"


char *path;

void ft_pwd(void)
{
	char *buffer = NULL;
	path = getcwd(buffer, sizeof(buffer));
	printf("%s\n", path);
}

void ft_cd(t_all mass)
{
	//chdir - сменить текущий каталог
	//Возвращается  0  в случае  успеха  и -1 в противном случае с установлением errno.
	// просто cd - переходит на уровень учетки
	int res;

	//char *path_s;
	ft_pwd();
	// printf("cd_str: %s\n", str);
	//path_s = ft_strjoin (path, str);
	res = chdir(mass.tmp[1]);
	printf("res: %d\n", res);
	if(res != 0)
		printf("Не могу перейти к каталогу\n");
	// else
	// 	printf("%s\n", path_s);
}

int ft_split_commands(t_all mass)
{
	int i = 0;
	char *home;
	int j = 0;

	j = words_count(mass.buf, ' ');
	mass.tmp = ft_split(mass.buf, ' ');
	printf("tmp0:%s\n", mass.tmp[0]);
	if(ft_strncmp(mass.tmp[0], "echo", 4) == 0)
	{
		if(j == 1)
		{
			if (ft_strlen(mass.tmp[0]) == 4)
				printf("\n");
			else
				printf("command not found\n");
		}
		else if(j > 1)
		{
			j = j - 1;
			printf("j: %d\n", j);
			while (mass.tmp[i + 1])
			{
				printf("%s ", mass.tmp[i + 1]);
				i++;
			}
			//write(1, "\n", 1);
			printf("\n");
		}
	}
	if (ft_strncmp(mass.tmp[0], "pwd", 3) == 0)
	{
		if (ft_strlen(mass.tmp[0]) == 3)
			ft_pwd();
		else
			printf("command not found\n");
	}
	if (ft_strncmp(mass.tmp[0], "cd", 2) == 0)
	{
		if(j == 1)
		{
			if(ft_strlen(mass.tmp[0]) == 2)
			{
				home = getenv("HOME");
				chdir(home);
			}
		}
		else if (j == 2)
			ft_cd(mass);
		else
			printf("No such file or directory\n");
	}
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
