#include "../minishell.h"

static int	ft_subsr_index_dec(char sym, int *ind, t_all *mass, char *line)
{
	mass->sub_quotes[mass->u_mass.iter] = *ind;
	(mass->u_mass.iter)++;
	(*ind)++;
	while (line[*ind] != '\0' && line[*ind] != sym)
		(*ind)++;
	if (line[*ind] == '\0')
	{
		printf("Warning: possible multiline! Program has stopped\n");
		return (0);
	}
	mass->sub_quotes[mass->u_mass.iter] = *ind;
	(mass->u_mass.iter)++;
	return (1);
}

int	ft_pars_quotes(char *line, t_all *mass)
{
	int		ind;

	ind = 0;
	mass->u_mass.iter = 0;
	while (line[ind] != '\0')
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
		mass->sub_quotes[0] = 0;
		mass->sub_quotes[1] = mass->count_sym - 1;
		(mass->u_mass.iter) += 2;
	}
	mass->sub_quotes[mass->u_mass.iter] = mass->count_sym;
	mass->sub_quotes[mass->u_mass.iter + 1] = mass->count_sym;
	return (0);
}

static void	util_subindex(t_all *mass, int *i_sub, int *i_quotes, int *end)
{
	if (*end > mass->sub_quotes[*i_quotes - 1])
	{
		mass->sub_indx[*i_sub] = mass->sub_quotes[*i_quotes - 1] + 1;
		mass->sub_indx[*i_sub + 1] = *end;
		*i_sub += 2;
	}
	mass->sub_indx[*i_sub] = *end + 1;
	mass->sub_indx[*i_sub + 1] = *end + 1;
}

void	ft_build_subindex(t_all *mass)
{
	int	end;
	int	start;
	int	i_quotes;
	int	i_sub;

	i_quotes = 0;
	i_sub = 0;
	end = mass->count_sym - 1;
	start = 0;
	while (mass->buf[mass->sub_quotes[i_quotes]] != '\0')
	{
		if (mass->sub_quotes[i_quotes] > start)
		{
			mass->sub_indx[i_sub] = start;
			mass->sub_indx[i_sub + 1] = mass->sub_quotes[i_quotes] - 1;
			i_sub += 2;
		}
		mass->sub_indx[i_sub] = mass->sub_quotes[i_quotes];
		mass->sub_indx[i_sub + 1] = mass->sub_quotes[i_quotes + 1];
		start = mass->sub_quotes[i_quotes + 1] + 1;
		i_sub += 2;
		i_quotes += 2;
	}
	util_subindex(mass, &i_sub, &i_quotes, &end);
}

void	ft_parser(t_all *mass)
{
	mass->count_sym = ft_strlen(mass->buf);
	mass->sub_indx = (int *)malloc(sizeof(int) * (mass->count_sym + 4));
	mass->sub_quotes = (int *)malloc(sizeof(int) * (mass->count_sym + 4));
	mass->sub_quotes[0] = 0;
	ft_bzero(mass->sub_indx, mass->count_sym + 4);
	ft_bzero(mass->sub_quotes, mass->count_sym + 4);
	if (ft_pars_quotes(mass->buf, mass) == -1)
		exit(-1);
	ft_build_subindex(mass);
	mass->flag_error = ft_token_decompose(mass);
}
