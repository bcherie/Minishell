#include "../minishell.h"

void echo_n(t_tokens *tok)
{
	int i;
	int j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;

	if(tok->count == 1)
	{
		printf("");
		return ;
	}
	if(tok->count > 1)
	{
		if(tok->args[0][0] == '-' && tok->args[0][1] == 'n')
		{
			// flag = 1;
			while (tok->args[0][j] == 'n')
				j++;
			while(tok->args[i + 1][0] == '-' && tok->args[i + 1][1] == 'n')
			{
				i++;
			}
		}
		tok->args++;
		// write(1, t_ptr->command->args++, ft_strlen(*t_ptr->command->args));
		while (tok->args[i])
		{
			write(1, tok->args[i], ft_strlen(tok->args[i]));
			if(tok->args[i + 1] != NULL)
				write(1, " ", 1);
			i++;
		}
		// }
	}
}

void	ft_echo(t_tokens *tok)
{
	int i;
	int j;
	int flag;
	//прописать тут флаг -n
	flag = 0;
	i = 0;
	j = 0;
	if (tok->count == 0)
	{
		if (ft_strlen(tok->container) == 4)
			printf("\n");
		else
			printf("command not found\n");
	}
	else if(tok->count >= 1)
	{
		while (i < tok->count)
		{
			if (!(ft_strnstr(tok->args[i], "-n", ft_strlen(tok->args[i]))))
			{
				flag = 0;
				write(1, tok->args[i], ft_strlen(tok->args[i]));
				if(tok->args[i + 1] != NULL)
					write(1, " ", 1);
			}
			else
			{
				flag = 1;
		 		echo_n(tok);
				break ;
			}
			i++;
		}
		if(flag != 1)
			printf("\n");
	}
}
