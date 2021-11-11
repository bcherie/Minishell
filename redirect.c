#include "minishell.h"
#include <fcntl.h>
//кейсы: export gggg > testf создаст файлб но не запишет
// echo 55 > > file.txt - doesn't work in our minishell
//args -> command, text
//out_r -> '>', file
void	ft_check_redirect(t_tokens *tok)
{
	int	i;
	int	j;
	int	count;
	int	fd;
	int	old_fd;
	char **tmp;
	// char *buf;

	i = 0;
	j = 0;
	count = 0;
	// buf = "hello";
	tmp = (char **)malloc(sizeof(char *));
	if (tok->out_redir[i])
	{
		while (tok->out_redir[i] != NULL)
		{
			if (*tok->out_redir[i] != 'r')
			{
				tmp[j] = tok->out_redir[i];
				count++;
				j++;
			}
			i++;
		}
	}
	// printf("buf: %s\n", tmp[0]);
	// printf("buf: %s\n", tmp[1]);
	// printf("count: %d\n", count);
	j = 0;
	i = 0;
	while (j != count)
	{
		fd = open(tmp[j], O_WRONLY | O_CREAT, 0644);
		if (fd < 0)
			printf ("error\n");
		old_fd = dup(fd); // save fd
		dup2(old_fd, 1);
		close(fd);
		if (j == count - 1)
		{
			write(old_fd, tok->args[i + 1], strlen(tok->args[i]));
			// close(old_fd);
			// break ;
			exit(0);
			// ft_exit(mass, tok);
		}
		// printf("Current INDEX - (%d)\n", i);
		j++;
	}
	// printf("\nXsdfsdfsdfX\n");
	// while (tok->out_redir[i] != NULL)
	// {
	// 	printf("out_r: %s\n", tok->out_redir[i]);
	// 	i++;
	// }
	// while (tok->args[j] != NULL)
	// {
	// 	printf("args: %s\n", tok->args[j]);
	// 	j++;
	// }

}
