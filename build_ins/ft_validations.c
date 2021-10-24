#include "../minishell.h"

int		ft_is_valid_env_token(char *command, char *val)
{
	if (ft_isalpha(val[0]) == 1 || val[0] == '_')
		return (1);
	ft_print_report(command, val, REPORT_IDENT);
	return (0);
}
