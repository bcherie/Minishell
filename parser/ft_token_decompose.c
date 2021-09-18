#include "../minishell.h"

int simple_startend_check(int start, int end)
{
	if (start < 0 || end < 0 || (end - start) < 0)
		return (0);
	return (1);
}

int	ft_spacekill(char *buf, int start, int end)
{
	int	new_start;

	if (simple_startend_check(start, end) == 0)
		return (-1);
	new_start = start;
	while (buf[new_start] == ' ' && new_start < end)
		new_start++;
	//можно попать на конец строки!
	if (buf[new_start] == ' ')
		new_start++;
	return (new_start);
}

int	ft_spacekill_left(char *buf, int start, int end)
{
	int	new_end;

	if (simple_startend_check(start, end) == 0)
		return (-1);
	new_end = end;
	while (buf[new_end] == ' ' && new_end > start)
		new_end--;
	return (new_end);
}

int ft_findcommand(char *buf, int start, int end)
{
	int	ret_end;

	ret_end = 0;
	if (simple_startend_check(start, end) == 0)
		return (-1);
	ret_end = start;

	while (buf[ret_end] != ' ' && buf[ret_end] != '\0' && ret_end < end)
		ret_end++;
	if (fpf_strchr(" \0", buf[ret_end]))
		ret_end--;
	return (ret_end);
}

int ft_checkkeysym(char *buf, t_utils *u)
{
	int		i;
	int		counter;
	char	sym;

	i = 0;
	sym = '<';
	counter = 0;
	if (simple_startend_check(u->n_st, u->end) == 0)
		return (-1);
	i = u->n_st;
	sym = buf[u->n_st];
	while (buf[i] == sym || buf[i] == ' ')
	{
		if (buf[i] == sym)
			counter++;
		i++;
	}
	if ((sym == '<' || sym == '>') && counter > 2)
		u->i_count = 0;
	else if (sym == '|' && counter != 1)
		u->i_count = 0;
	else
		u->i_count = counter;
	u->i_keyshift = i;
	return (i);
}

int ft_findrange(char *buf, int start, int end)
{
	int	ret_end;

	ret_end = 0;
	if (simple_startend_check(start, end) == 0)
		return (-1);
	ret_end = start;
	while (!fpf_strchr("<>|\0", buf[ret_end]) && ret_end < end)
		ret_end++;
	if (fpf_strchr("<>|", buf[ret_end]))
	{
		ret_end--;
		ret_end = ft_spacekill_left(buf, start, ret_end);
	}
	if (buf[ret_end] == '\0')
		ret_end--;
	return (ret_end);
}

static int ft_pretoken_check(char *string, int start, int end)
{
	if (start < 0 || end < 0 || string == NULL || end - start < 0)
		return (-1);
	if (&string[start] == NULL || &string[end] == NULL)
		return (-2);
	if (string[start] == '\0' || string[end] == '\0')
		return (0);
	if (string[start] == 34 || string[start] == 39)
		return (1);
	return (2);
}

void	ft_token_keys(char sym, int count, t_tokens *token)
{
	if (sym == '|')
		token->type = 'p';
	if (sym == '<')
	{
		if (count == 1)
			token->type = 'l';
		if (count == 2)
			token->type = 'L';
	}
	if (sym == '>')
	{
		if (count == 1)
			token->type = 'r';
		if (count == 2)
			token->type = 'R';
	}
}

void ft_pretoken_count(t_all *mass)
{
	int	count;
	int	i;
	int	checker;

	count = 0;
	i = 0;
	checker = 1;
	while (checker == 1)
	{
		if (mass->buf[mass->sub_indx[i]] == '\0' || mass->buf[mass->sub_indx[i] + 1] == '\0')
			checker = 0;
		else
		{
			count++;
			i = i + 2;
		}
	}
	mass->number_of_pretokens = count;
}

int	ft_token_decompose(t_all *mass)
{
	t_tokens	*tmp_token;
	t_utils		u;
	int			i;
	int			ret;

	i = 0;
	ret = 1;
	//building mass->tmp_container
	mass->tmp = (char**)malloc(sizeof(char*) * 3);
	mass->tmp[2] = NULL;
	ft_pretoken_count(mass);
	u.iter = 0;
	u.flag_find_command = 1;
	u.flag_token_join = 0;
	//
	//token_differentiator
	while(ret > 0 && u.iter < mass->number_of_pretokens)
	{
		u.st = mass->sub_indx[i];
		u.end = mass->sub_indx[i + 1];
		u.n_st = u.st;
		u.n_end = u.end;
		ret = ft_pretoken_check(mass->buf, u.st, u.end);
		while (u.n_st < u.end)
		{
			if (ret == 2)
			{
				u.n_st  = ft_spacekill(mass->buf, u.n_st, u.end);
				if (fpf_strchr("<>|", mass->buf[u.n_st]))
				{
					//
					ft_checkkeysym(mass->buf, &u);
					//
					if (u.i_count <= 0)
					{
						//значит пайп или редирект невалиден
						//или значения были ложными, короче что-то пошло не так
						return (-1);
					}
					else
					{
						tmp_token = ft_token_add(mass);
						ft_token_keys(mass->buf[u.n_st], u.i_count, tmp_token);
						u.n_st = u.i_keyshift;
						u.flag_find_command = 1;
						u.flag_token_join = 0;
					}
				}
				else
				{
					u.n_end = ft_findrange(mass->buf, u.n_st, u.end);
					if (u.flag_find_command == 1)
					{
						tmp_token = ft_token_add(mass);
						u.c_end = ft_findcommand(mass->buf, u.n_st, u.n_end);
						mass->tmp[1] = ft_substr(mass->buf, u.n_st, u.c_end - u.n_st + 1);
						tmp_token->container = mass->tmp[1];
						tmp_token->type = 'c';
						u.flag_find_command = 0;
						u.n_st = u.c_end + 1;
					}
					else
					{
						if (u.flag_token_join == 0)
						{
							tmp_token = ft_token_add(mass);
							mass->tmp[1] = ft_substr(mass->buf, u.n_st, u.n_end - u.n_st + 1);
							tmp_token->container = mass->tmp[1];
							tmp_token->type = 'a';
							u.flag_token_join = 1;
						}
						else
						{
							mass->tmp[2] = mass->tmp[1];
							mass->tmp[1] = ft_substr(mass->buf, u.n_st, u.n_end - u.n_st + 1);
							tmp_token->container = ft_strjoin(tmp_token->container, mass->tmp[1]);
							free(mass->tmp[1]);
							free(mass->tmp[2]);
						}
						u.n_st = u.n_end + 1;
					}
				}
			}
			else if (ret == 1)
			{
				u.n_st++;
				u.n_end--;
				if (u.flag_token_join == 0)
				{
					tmp_token = ft_token_add(mass);
					mass->tmp[1] = ft_substr(mass->buf, u.n_st, u.n_end - u.n_st + 1);
					tmp_token->container = mass->tmp[1];
					u.flag_token_join = 1;
				}
				else
				{
					mass->tmp[2] = mass->tmp[1];
					mass->tmp[1] = ft_substr(mass->buf, u.n_st, u.n_end - u.n_st + 1);
					tmp_token->container = ft_strjoin(tmp_token->container, mass->tmp[1]);
					free(mass->tmp[1]);
					free(mass->tmp[2]);
				}
				u.n_st = u.n_end + 2;
			}
		}
		i = i + 2;
		u.iter++;
	}
	t_tokens *tmp2;

	tmp2 = mass->tokens;
	while (tmp2 != NULL)
	{
		//printf("\nDecomposed: IND - (%d): container - (%s): type - (%c)\n", tmp2->index, tmp2->container, tmp2->type);
		tmp2 = tmp2->next;
	}
	// cleaner
	// start from ""
	// one sym after ' " - ('d)
	//	flag / tilda
	// 	dollar
	// < file cat
	// --n
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
