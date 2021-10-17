#include "minishell.h"

void	tmp_int_cleaner(t_all *mass, int mode)
{
	int	i;

	i = 0;
	if (mass->tmp == NULL)
		return ;
	while (i < 3)
	{
		if (mass->tmp[i] != NULL)
		{
			free(mass->tmp[i]);
			mass->tmp[i] = NULL;
		}
		i++;
	}
	if (mode == 1)
	{
		free(mass->tmp);
		mass->tmp = NULL;
	}
}

void global_cleaner(t_all *mass, int mode)
{
	tmp_int_cleaner(mass, 1);
	if (mass->buf != NULL)
	{
		free(mass->buf);
		mass->buf = NULL;
	}
	if (mode == 1 && mass != NULL)
	{	
		free(mass);
		mass = NULL; 
	}
}

int	init_t_alls(t_all *mass)
{
	ft_bzero(mass, sizeof(t_all));
	mass->tmp = (char **)malloc(sizeof(char *) * 3);
	if (mass->tmp == NULL)
		return (0);
	mass->tmp[0] = NULL;
	mass->tmp[1] = NULL;
	mass->tmp[2] = NULL;
	return (1);
}