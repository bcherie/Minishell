#include "../minishell.h"

void	ft_pretoken_count(t_all *mass)
{
	int	count;
	int	i;
	int	checker;

	count = 0;
	i = 0;
	checker = 1;
	while (checker == 1)
	{
		if (mass->buf[mass->sub_indx[i]] == '\0' || \
		mass->buf[mass->sub_indx[i + 1]] == '\0')
			checker = 0;
		else
		{
			count++;
			i = i + 2;
		}
	}
	mass->number_of_pretokens = count;
}

void	ft_init_utils_struct(t_utils *u)
{
	u->iter = 0;
	u->flag_find_command = 1;
	u->flag_token_join = 0;
	u->flag_find_file = 0;
	u->flag_dollar_on = 1;
	u->i_keyshift = 0;
	u->i_count = 0;
	u->st = 0;
	u->n_st = 0;
	u->end = 0;
	u->n_end = 0;
}
