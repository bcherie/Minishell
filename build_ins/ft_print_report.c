#include "../minishell.h"

void ft_print_report(char *command, char *val, int type)
{
	if (type == REPORT_IDENT)
		printf("minishell: %s: %s is not valid identifier\n", command, val);
}