#include "../minishell.h"

static int	validation_tool(t_tokens *tok)
{
	if (tok->type == 'p')
	{
		if (tok->next == NULL || tok->next->type == 'p')
		{
			printf("UPPER VALIDATION\n");
			ft_print_report(NULL, NULL, REP_SYNTAX_P);
			return (FLAG_ERROR);
		}
	}
	else
	{
		if (tok->next == NULL || tok->next->type != 'f')
		{
			printf("UPPER VALIDATION\n");
			if (tok->type == 'R' || tok->type == 'r')
				ft_print_report(NULL, NULL, REP_SYNTAX_R);
			if (tok->type == 'l')
				ft_print_report(NULL, NULL, REP_SYNTAX_L);
			if (tok->type == 'L')
				ft_print_report(NULL, NULL, REP_SYNTAX_HEREDOC);
			return (FLAG_ERROR);
		}
	}
	return (FLAG_GOOD);
}

int	ft_validate_token_syms(t_all *mass)
{
	t_tokens	*tmp;

	tmp = NULL;
	if (mass->tokens != NULL && mass->flag_error != FLAG_ERROR)
	{
		tmp = mass->tokens;
		while (tmp != NULL)
		{
			if (tmp->type != 'c' && tmp->type != 'a' && tmp->type != 'f')
			{
				if (validation_tool(tmp) == FLAG_ERROR)
					return (FLAG_ERROR);
			}
			tmp = tmp->next;
		}
		return (FLAG_GOOD);
	}
	return (FLAG_ERROR);
}
