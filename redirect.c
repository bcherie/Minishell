#include "minishell.h"
#include <fcntl.h>
//кейсы: export gggg > testf создаст файлб но не запишет
// echo 55 > > file.txt - doesn't work in our minishell
// < new cat
// < new echo
//args -> command, text
//out_r -> '>', file

static void left_redirect(t_tokens *tok)
{
	int 	j;

	j = 0;
	while (tok->in_redir[i] != NULL)
	{
		if (*tok->in_redir[i] != 'l' && *tok->in_redir[i] != 'L')
		{
			tmp[j] = tok->in_redir[i];
			j++;
		}
		else
		{
			if (*tok->in_redir[i] == 'l')
				flag_l = 1;
			else if (*tok->in_redir[i] == 'L')
				flag_l = 2;
		}
		i++;
	}

}

static void	right_redirect(t_tokens *tok)
{
	int 	j;

	j = 0;
	while (tok->out_redir[i] != NULL)
	{
		if (*tok->out_redir[i] != 'r' && *tok->out_redir[i] != 'R')
		{
			tmp[j] = tok->out_redir[i];
			j++;
		}
		else
		{
			if (*tok->out_redir[i] == 'r')
				flag_r = 1;
			else if (*tok->out_redir[i] == 'R')
			{
				flag_r = 2;
			}
		}
		i++;
	}

}

void	ft_check_redirect(t_tokens *tok)
{
	int	i;
	int	j;
	int	fd;
	int	old_fd;
	char **tmp;
	// int	flag_r;
	// int	flag_l;
	char *buf;

	i = 0;
	j = 0;
	// flag_r = 0;
	// flag_l = 0;
	tmp = (char **)malloc(sizeof(char *));

	//check commands

	// printf("out: %d\n", tok->out_n);
	// printf("inp: %d\n", tok->inp_n);
	// printf("\nVVVVVVVVVVVV\n");

	//write in file
	if (tok->out_n != 0)
	{
		left_redirect(tok)
	}
	if (tok->inp_n != 0)
	{
		left_redirect(tok);
	}

	// printf("buf: %s\n", tmp[0]);
	// printf("buf: %s\n", tmp[1]);
	// printf("count: %d\n", count);
	//O_APPEND - параметр опен для дозаписи в файл данных
	j = 0;
	i = 1;
	// printf("len_arg: %lu\n", strlen(tok->args[i]));
	while (j != tok->out_n)
	{
		// printf("out: %d\n", tok->out_n);
		if (flag_r == 1)
			fd = open(tmp[j], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (flag_r == 2)
			fd = open(tmp[j], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd < 0)
			printf ("error\n");
		old_fd = dup(fd); // save fd
		dup2(old_fd, 1);
		close(fd);
		j++;
	}
	i = 0;
	j = 0;
	while (j != tok->inp_n)
	{
		if (flag_l == 1)
			fd = open(tmp[j], O_RDONLY, 0644);
		else if (flag_l == 2)
		{
			fd = open(tmp[j], O_RDONLY, 0644);
		}
		if (fd < 0)
			printf ("error\n");
		old_fd = dup(fd); // save fd
		dup2(old_fd, 0);
		close(fd);
		j++;
	}

}
