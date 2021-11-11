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

	i = 0;
	j = 0;
	if (tok->out_redir[i])
	{
		
	}
	while (tok->out_redir[i] != NULL)
	{
		printf("out_r: %s\n", tok->out_redir[i]);
		i++;
	}
	while (tok->args[j] != NULL)
	{
		printf("args: %s\n", tok->args[j]);
		j++;
	}

}
