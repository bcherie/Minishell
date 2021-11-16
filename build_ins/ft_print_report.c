/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_report.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:56:15 by droro             #+#    #+#             */
/*   Updated: 2021/11/16 23:10:29 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	else if (type == REP_SYNTAX_R)
		printf("minishell: syntax error near unexpected token \'>\'\n");
	else if (type == REP_SYNTAX_L)
		printf("minishell: syntax error near unexpected token  \'<\'\n");
	else if (type == REP_SYNTAX_P)
		printf("minishell: syntax error near unexpected token  \'|\'\n");
	else if (type == REP_SYNTAX_HEREDOC)
		printf("minishell: syntax error near unexpected token  \'newline\'\n");
	else
		perror("minishell: ");
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
