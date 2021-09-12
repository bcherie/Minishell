#include "../minishell.h"

int	ft_space_cleaner(char *buf, int start, int end)
{
	int	new_start;

	if (start < 0)
		return (-1);
	new_start = start;
	while (buf[new_start] == ' ' && new_start < end)
		new_start++;
	//можно попать на конец строки!
	if (buf[new_start] == ' ')
		new_start++;
	return (new_start);
}

int ft_command_finder(char *buf, int start, int end)
{
	int	ret_end;

	ret_end = 0;
	if (start < 0 || end < 0 || (end - start) <= 0)
		return (-1);
	ret_end = start;
	
	while (!fpf_strchr(" <>|", buf[ret_end]) && ret_end < end)
		ret_end++;
	if (fpf_strchr(" <>|", buf[ret_end]))
		ret_end--;	
	return (ret_end);
}

int	ft_token_decompose(t_all *mass)
{
	char	*buf;
	int		st;
	int 	end[2];
	int		i;
	char	sym;

	sym = NULL;
	t_tokens	*tmp_check;
	// t_tokens	*flags;

	buf = mass->buf;
	mass->tmp = (char**)malloc(sizeof(char*) * 3);
	mass->tmp[2] = NULL;
	i = 0;
	st = mass->substr_inds[i];
	end[0] = mass->substr_inds[i + 1];
	st = ft_space_cleaner(buf, st, end[0]);
	i += 2;
	end[1] = ft_command_finder(buf, st, end[0]);
	mass->tmp[1] = ft_substr(buf, st, end[1] - st + 1);
	//printf("\nDecomposed_Value-%s\n", mass->tmp[1]);
	
	tmp_check = ft_token_add(mass);
	if(tmp_check == NULL)
		return(-1);
	tmp_check->container = mass->tmp[1];
	printf("\nDecomposed_tmp: %s\n", tmp_check->container);
	//	pipe
	//	redirect
	//	flag / tilda
	// 	dollar
	//	space
	// 	words
	st = end[1] +1;
	st = ft_space_cleaner(buf, st, end[0]);
	//end[1] = ft_command_finder(buf, st, end[0]);
	mass->tmp[2] = ft_substr(buf, st, end[0] - st +1);
	// while ()
	printf("\nDecomposed_tmp2:%s\n", mass->tmp[2]);
	if(sym = ft_strchr(" <>|", mass->tmp[2])
	{
		if(sym == '<' || sym == '>')
			mass->tokens->redir = sym;
		if(sym == '|')
			masspipe = sym;
	}
	else

	// while ()

	// quotes - обносление начала-конца 

	// tmp_check->flags-> = mass->tmp[2];
	// printf("\nDecomposed_tmp2: %s\n", tmp_check->flags);
	return (0);
}

// int ft_parse_command(t_all *mass)
// {
// 	if(ft_strncmp(mass->tmp[1], "echo", 5) == 0)
// 	{
// 		ft_echo(mass);
// 		mass->tokens.type = 'b';
// 	}
// 	// else if(ft_strncmp(mass.tmp[0], "pwd", 4) == 0)
		

// 	printf("\nDecomposed_Value-%s\n", mass->tmp[1]);

// }