#include "minishell.h"
#include <fcntl.h>
//кейсы: export gggg > testf создаст файлб но не запишет
// echo 55 > > file.txt - doesn't work in our minishell
// < new cat
// < new echo
//args -> command, text
//out_r -> '>', file
void	ft_check_redirect(t_tokens *tok)
{
	int	i;
	int	j;
	int	fd;
	int	old_fd;
	char **tmp;
	int	flag_r;
	int	flag_l;
	char	*line = NULL;
	int	num = 0;

	i = 0;
	j = 0;
	flag_r = 0;
	flag_l = 0;
	tmp = (char **)malloc(sizeof(char *));

	//check commands

	// printf("out: %d\n", tok->out_n);
	// printf("inp: %d\n", tok->inp_n);
	// printf("\nVVVVVVVVVVVV\n");

	//write in file
	if (tok->out_n != 0)
	{
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
					flag_r = 2;
			}
			i++;
		}
	}
	if (tok->inp_n != 0)
	{
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
		// if (tok->out_n == 1)
		// {
		// 	while (tok->args[i])
		// 	{
		// 		write(old_fd, tok->args[i], strlen(tok->args[i]));
		// 		i++;
		// 	}
		// 	if (flag_r == 2)
		// 		write(old_fd, "\n", 1);
		// 	exit(0);
		// }
		// else if (tok->out_n > 1)
		// {
		// 	if (j == tok->out_n - 1)
		// 	{
		// 		write(old_fd, tok->args[i + 1], strlen(tok->args[i + 1]));
		// 		if (flag_r == 2)
		// 			write(old_fd, "\n", 1);
		// 		exit(0);
		// 	}
		// }
		// printf("Current INDEX - (%d)\n", i);
		j++;
	}
	i = 0;
	j = 0;
	while (j != tok->inp_n)
	{
		if (flag_l == 1)
			fd = open(tmp[j], O_RDONLY | O_CREAT, 0644);
		else if (flag_l == 2)
			fd = open(tmp[j], O_RDONLY | O_CREAT, 0644);
		if (fd < 0)
			printf ("error\n");
		old_fd = dup(fd); // save fd
		dup2(old_fd, 1);
		close(fd);
		if (tok->inp_n == 1)
		{
			while (num > 0)
			{
				get_next_line(old_fd, &line);
				num--;
			}
			// while (get_next_line(old_fd, &line) > 0)
			// 	write(1, line, strlen(line));
			// if (flag_r == 2)
			// 	write(old_fd, "\n", 1);
			exit(0);
		}
		else if (tok->inp_n > 1)
		{
			if (j == tok->inp_n - 1)
			{
				write(old_fd, tok->args[i + 1], strlen(tok->args[i + 1]));
				if (flag_l == 2)
					write(1, "\n", 1);
				exit(0);
			}
		}
		// printf("Current INDEX - (%d)\n", i);
		j++;
	}

}









#include "minishell.h"
#include <fcntl.h>
//кейсы: export gggg > testf создаст файлб но не запишет
// echo 55 > > file.txt - doesn't work in our minishell
// < new cat
// < new echo
//args -> command, text
//out_r -> '>', file
//echo LLL > file1 test < file2

void heredok(t_tokens *tok)
{
	int i;
	char *keyword;
	char *line;
	// pid_t pid;

	i = 0;
	line = (char *)malloc(sizeof(char *));
	keyword = tok->tmp_in[0];
	printf ("keyword: %s\n", keyword);
	if (tok->flag_l == 2)
	{
		// pid = fork = ();
		while (1)
		{
			line = readline("> ");
			if (ft_strlen(line) > 0)
			{
				while (*line)
				{
					if (ft_strncmp(line, keyword, ft_strlen(line)) == 0)
						exit(0);
					(*line)++;
				}
			}
		}
	}

}

void	redir_flag(t_tokens *tok)
{
	// int	flag_r;
	// int	flag_l;
	// char **tmp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tok->flag_r = 0;
	tok->flag_l = 0;
	tok->tmp_out = (char **)malloc(sizeof(char *));
	tok->tmp_in = (char **)malloc(sizeof(char *));
	if (tok->out_n != 0)
	{
		while (tok->out_redir[i] != NULL)
		{
			if (*tok->out_redir[i] != 'r' && *tok->out_redir[i] != 'R')
			{
				tok->tmp_out[j] = tok->out_redir[i];
				j++;
			}
			else
			{
				if (*tok->out_redir[i] == 'r')
					tok->flag_r = 1;
				else if (*tok->out_redir[i] == 'R')
					tok->flag_r = 2;
			}
			i++;
		}
	}
	i = 0;
	j = 0;
	if (tok->inp_n != 0)
	{
		while (tok->in_redir[i] != NULL)
		{
			if (*tok->in_redir[i] != 'l' && *tok->in_redir[i] != 'L')
			{
				tok->tmp_in[j] = tok->in_redir[i];
				j++;
			}
			else
			{
				if (*tok->in_redir[i] == 'l')
					tok->flag_l = 1;
				else if (*tok->in_redir[i] == 'L')
					tok->flag_l = 2;
			}
			i++;
		}
	}
}

void	ft_check_redirect(t_tokens *tok)
{
	int	i;
	int	j;
	int	fd;
	int	old_fd;
	// int	flag_r;
	// int	flag_l;
	// char	*line = NULL;
	// int	num = 0;

	//O_APPEND - параметр опен для дозаписи в файл данных
	j = 0;
	i = 1;
	// printf("len_arg: %lu\n", strlen(tok->args[i]));
	while (j != tok->out_n)
	{
		// printf("out: %d\n", tok->out_n);
		if (tok->flag_r == 1)
			fd = open(tok->tmp_out[j], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (tok->flag_r == 2)
			fd = open(tok->tmp_out[j], O_WRONLY | O_CREAT | O_APPEND, 0644);
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
		if (tok->flag_l == 1)
			fd = open(tok->tmp_in[j], O_RDONLY | O_CREAT, 0644);
		else if (tok->flag_l == 2)
			fd = open(tok->tmp_in[j], O_RDONLY | O_CREAT, 0644);
		if (fd < 0)
			printf ("error\n");
		old_fd = dup(fd); // save fd
		dup2(old_fd, 0);
		close(fd);
		j++;
	}

}

