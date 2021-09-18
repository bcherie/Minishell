#include "../minishell.h"

// static void ft_print_substr(t_all *mass)
// {
// 	int i;

// 	i = 2;
// 	write(1, &mass->buf[mass->sub_indx[0]], mass->sub_indx[1] - mass->sub_indx[0] + 1);
// 	write(1,"\n", 1);
// 	while(mass->sub_indx[i - 1] != 0)
// 	{
// 		write(1, &mass->buf[mass->sub_indx[i]], mass->sub_indx[i + 1] - mass->sub_indx[i] + 1);
// 		i = i + 2;
// 		write(1,"\n", 1);
// 	}
// }

static int	ft_subsr_index_dec(char sym, int *ind, t_all *mass, char *line)
{
	mass->sub_prev[mass->u_mass.iter] = *ind;
	(mass->u_mass.iter)++;
	(*ind)++;
	while (line[*ind] != '\0' && line[*ind] != sym)
		(*ind)++;
	if (line[*ind] == '\0')
	{
		printf("Warning: possible multiline! Program has stopped\n");
		return (0);
	}
	mass->sub_prev[mass->u_mass.iter] = *ind;
	(mass->u_mass.iter)++;
	return (1);
}

int		ft_pars_quotes(char *line, t_all *mass)
{
	int		ind;

	ind = 0;
	mass->u_mass.iter = 0;
	while(line[ind] != '\0')
	{
		if (line[ind] == 34 || line[ind] == 39)
		{
			if (!ft_subsr_index_dec(line[ind], &ind, mass, line))
				return (-1);
		}
		ind++;
	}
	if (mass->u_mass.iter == 0)
	{
		mass->sub_prev[0] = 0;
		mass->sub_prev[1] = mass->count_sym - 1;
		mass->sub_prev[2] = mass->count_sym;
		mass->sub_prev[3] = mass->count_sym;
	}
	return (0);
}

int		ft_build_subindex(t_all *mass)
{
	int	end;
	int	start;
	int	i_prev;
	int	i_sub;

	i_prev = 0;
	i_sub = 0;
	end = mass->count_sym - 1;
	start = 0;
	while (mass->sub_prev[i_prev + 1] != 0)
	{
		if (mass->sub_prev[i_prev] > start)
		{
			mass->sub_indx[i_sub] = start;
			mass->sub_indx[i_sub + 1] = mass->sub_prev[i_prev] - 1;
			i_sub += 2;	
		}
		mass->sub_indx[i_sub] = mass->sub_prev[i_prev];
		mass->sub_indx[i_sub + 1] = mass->sub_prev[i_prev + 1];
		start = mass->sub_prev[i_prev + 1] + 1;
		i_sub += 2;
		i_prev += 2;
	}
	if (end > mass->sub_prev[i_prev - 1])
	{
		mass->sub_indx[i_sub] = mass->sub_prev[i_prev - 1] + 1;
		mass->sub_indx[i_sub + 1] = end;
		i_sub += 2;
	}
	mass->sub_indx[i_sub] = end + 1;
	return (1);
}

void	ft_parser(t_all *mass)
{
	//добавьте обработку случая на 0 символов
	mass->count_sym = ft_strlen(mass->buf);
	mass->sub_indx = (int*)malloc(sizeof(int) * (mass->count_sym + 4));
	mass->sub_prev = (int*)malloc(sizeof(int) * (mass->count_sym + 4));
	mass->sub_prev[0] = 0;
	ft_bzero(mass->sub_indx, mass->count_sym + 4);
	ft_bzero(mass->sub_prev, mass->count_sym + 4);
	if (ft_pars_quotes(mass->buf, mass) == -1)
		exit(-1);
	ft_build_subindex(mass);
	//ft_print_substr(mass);
	ft_token_decompose(mass);
}