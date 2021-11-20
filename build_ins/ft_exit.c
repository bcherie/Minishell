#include "../minishell.h"

void	ft_exit(t_all *mass, t_tokens *tok)
{
	long long	exit_number;

	exit_number = 0;
	if (tok != NULL && tok->count > 0)
	{
		if (ft_ms_atoi_checksyms(tok->args[1]) == 0)
		{
			printf("exit\n");
			ft_print_report(tok->container, tok->args[1], REP_NUMARG);
		}
		else
		{
			exit_number = ft_atolonglong(tok->args[1]);
			printf("exit\n");
		}
	}
	else
		printf("exit\n");
	global_cleaner(mass, 1);
	exit(exit_number);
}
