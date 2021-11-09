#include "../minishell.h"

static void	to_home(t_all *mass, t_tokens *tok)
{
	t_tokens	*env_token;
	char		*home;
	int			res;

	res = 1;
	env_token = ft_is_in_enviroment(mass, "HOME");
	if (env_token->type == ENV_TOK_UNSET)
		ft_print_report(tok->container, "HOME", REP_UNSET_PARAM);
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
				ft_print_report(tok->container, env_token->value, REP_NOFDIR);
		}
	}
}

void	ft_cd(t_all *mass, t_tokens *tok)
{
	int		res;
	char	*home;

	res = 1;
	if (tok->count == 0)
		to_home(mass, tok);
	else if (tok->count > 0)
	{
		if ((tok->args[1][0] == '~' && ft_strlen(tok->args[1]) == 1) || \
		(tok->args[1][0] == '\0'))
			to_home(mass, tok);
		else
		{
			home = ft_envops_getval(mass, "PWD");
			res = chdir(tok->args[1]);
			if (res != 0)
				ft_print_report(tok->container, tok->args[1], REP_NOFDIR);
			else
			{
				ft_envops_setval(mass, "OLDPWD", home);
				ft_envops_setval(mass, "PWD", ft_pwd(0));
			}
		}
	}
}
