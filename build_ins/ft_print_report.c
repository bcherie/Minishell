#include "../minishell.h"

void	ft_print_report(char *command, char *val, int type)
{
	if (type == REP_IDENT)
		printf("minishell: %s: %s: is not valid identifier\n", command, val);
	else if (type == REP_NOFDIR)
		printf("minishell: %s: %s: No such file or directory\n", command, val);
	else if (type == REP_NUMARG)
		printf("minishell: %s: %s: numeric argument required\n", command, val);
	else if (type == REP_NOFCOMMAND)
		printf("minishell: %s: command not found\n", command);
	else if (type == REP_UNSET_PARAM)
		printf("minishell: %s: HOME not set\n", command);
	else
		return ;
}

void	ft_print_env_token(t_tokens *tok, char mode)
{
	if (mode == ENV_TOK_FULL)
	{
		if (tok->type == mode)
			printf("%s=%s\n", tok->key, tok->value);
	}
	else if (mode == ENV_TOK_PARTIAL)
	{
		if (tok->type == ENV_TOK_PARTIAL || tok->type == ENV_TOK_FULL)
		{
			if (tok->value != NULL)
				printf("declare -x %s=\"%s\"\n", tok->key, tok->value);
			else
				printf("declare -x %s=\"\"\n", tok->key);
		}
	}
	else
		return ;
}
