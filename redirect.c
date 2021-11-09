#include "minishell.h"
#include <fcntl.h>
//кейсы: export gggg > testf создаст файлб но не запишет

void	ft_check_redirect(t_tokens *tok)
{
	// FILE	*file;
	int		fd;
	int		count;
	int		i;
	int		j;

	i = 0;
	j = 1;
	count = 0;
	//прописать пропуск "> > >"
	if (tok->type == 'r' || tok->type == 'R')
	{

		if (tok->type == 'r')
		{
			while (tok->args[i])
			{
				if (*tok->args[i] == '>')
					count++;
				i++;
			}
			if (count == 1)
			{
				if(*tok->args[i] == '>')
				{
					i++;
					fd = open(tok->args[i], O_CREAT | O_RDWR);
				}
				while (*tok->args[j] != '>')
				{
					write(fd, tok->args[j] , ft_strlen(tok->args[j]));
					j++;
				}
			}
			if (count > 1)
			{
				STDOUT = dup(fd);
			}

		}
	}
}
