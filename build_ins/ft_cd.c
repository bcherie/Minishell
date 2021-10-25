#include "../minishell.h"

void ft_cd(t_all *mass, t_tokens *tok)
{
	t_tokens	*env_token;
	int res;
	char *home;
	int i = 0;
	res = 1;

	if(tok->count == 0)
	{
		env_token = ft_is_in_enviroment(mass, "HOME");
		if (env_token->type == ENV_TOK_UNSET)
			ft_print_report(tok->container, "HOME", REPORT_UNSET_PARAM);
		else
		{
			home = ft_envops_getval(mass, "HOME");
			res = chdir(home);
			if (res == 0)
			{
				ft_envops_setval(mass, "OLDPWD", ft_envops_getval(mass, "PWD"));
				ft_envops_setval(mass, "PWD", home);
			}
			else
			{
				if (env_token->value != NULL)
					ft_print_report(tok->container, env_token->value, REPORT_NOFDIR);
			}
		}
	}
	else if (tok->count > 0)
	{
		if (tok->args[0][i] == '~' && ft_strlen(tok->args[i]) == 1)
		{
			env_token = ft_is_in_enviroment(mass, "HOME");
			if (env_token->type == ENV_TOK_UNSET)
				ft_print_report(tok->container, "HOME", REPORT_UNSET_PARAM);
			else
			{
				home = ft_envops_getval(mass, "HOME");
				res = chdir(home);
				if (res == 0)
				{
					ft_envops_setval(mass, "OLDPWD", ft_envops_getval(mass, "PWD"));
					ft_envops_setval(mass, "PWD", home);
				}
				else
				{
					if (env_token->value != NULL)
						ft_print_report(tok->container, env_token->value, REPORT_NOFDIR);
				}
			}
		}
		else
		{
			home = ft_envops_getval(mass, "PWD");
			res = chdir(tok->args[i]);
			if (res != 0)
				ft_print_report(tok->container, tok->args[i], REPORT_NOFDIR);
			else
			{
				ft_envops_setval(mass, "OLDPWD", home);
				ft_envops_setval(mass, "PWD", tok->args[i]);
			}
		}
	}
}
