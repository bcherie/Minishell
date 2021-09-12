#include "../minishell.h"
static void ft_print_substr(t_all *mass)
{
	int i;

	i = 2;
	write(1, &mass->buf[mass->substr_inds[0]], mass->substr_inds[1] - mass->substr_inds[0] + 1);
	write(1,"\n", 1);
	while(mass->substr_inds[i] != 0)
	{
		write(1, &mass->buf[mass->substr_inds[i]], mass->substr_inds[i + 1] - mass->substr_inds[i] + 1);
		i = i + 2;
		write(1,"\n", 1);
	}
}

static void	ft_subsr_index_dec(char sym, int ind, int *i_substr, t_all *mass)
{
	if (*i_substr == 0 && ind != 0)
	{
		(*i_substr)++;
		mass->substr_inds[*i_substr] = ind - 1;
		(*i_substr)++;
		mass->substr_inds[*i_substr] = ind;
	}
	else if (*i_substr % 2 != 0)
	{
		if (mass->buf[mass->substr_inds[*i_substr - 1]] == sym)
		{
			mass->substr_inds[*i_substr] = ind;
			(*i_substr)++;
			mass->substr_inds[*i_substr] = ind + 1;
		}
		else
		{
			mass->substr_inds[*i_substr] = ind - 1;
			(*i_substr)++;
			mass->substr_inds[*i_substr] = ind;
		}
	}
	else
		mass->substr_inds[*i_substr] = ind;
	(*i_substr)++;
}

int		ft_pars_quotes(char *line, t_all *mass)
{
	char	find_q;
	int		index;
	int		i_substr;

	index = 0;
	i_substr = 0;
	find_q = '"';
	while(line[index] != '\0')
	{
		if (line[index] == 34 || line[index] == 39)
		{
			find_q = line[index];
			ft_subsr_index_dec(find_q, index, &i_substr, mass);
			index++;
			while (line[index] != '\0')
			{
				if (line[index]== find_q)
				{
					ft_subsr_index_dec(find_q, index, &i_substr, mass);
					break ;
				}
				else
					index++;			
			}
			if (line[index] == '\0')
			{
				printf("Possible Multiline\n");
				free(mass->substr_inds);
				return (-1);
			}
		}
		index++;
	}
	ft_subsr_index_dec(find_q, index, &i_substr, mass);
	return (0);
}


void	ft_parser(t_all *mass)
{
	//добавьте обработку случая на 0 символов
	mass->count_sym = ft_strlen(mass->buf);
	mass->substr_inds = (int*)malloc(sizeof(int) * mass->count_sym);
	mass->substr_inds[0] = 0;
	ft_bzero(mass->substr_inds, mass->count_sym);
	if (ft_pars_quotes(mass->buf, mass) == -1)
		exit(-1);
	ft_print_substr(mass);
}