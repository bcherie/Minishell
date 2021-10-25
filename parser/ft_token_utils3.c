#include "../minishell.h"

void	ft_token_join_test(t_all *mass, t_utils *u)
{
	char		prev_char;
	t_tokens	*last;

	prev_char = 'x';
	last = ft_find_last_token(mass->tokens);
	u->flag_token_join = 0;
	if (u->iter > 0)
	{
		prev_char = mass->buf[u->n_st - 1];
		if (!fpf_strchr("RrLlp", last->type))
		{
			if (prev_char != ' ')
				u->flag_token_join = 1;
		}
	}
}

void	ft_token_name(t_tokens *tmp_token, t_utils *u)
{
	if (u->flag_find_file == 1)
	{
		u->flag_find_file = 0;
		tmp_token->type = 'f';
	}
	else if (u->flag_find_command == 1)
	{
		u->flag_find_command = 0;
		tmp_token->type = 'c';
	}
	else
		tmp_token->type = 'a';
}
