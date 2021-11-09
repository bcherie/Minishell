#include "../minishell.h"

int	ft_findcommand(char *buf, int start, int end)
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

void	ft_checkkeysym_assist(char sym, int counter, t_utils *u, char *buf)
{
	u->i_count = counter;
	if (sym == '<' || sym == '>')
	{
		if (counter > 2)
			u->i_count = 0;
		if (counter == 2 && buf[u->n_st + 1] != sym)
			u->i_count = 0;
	}
	else if (sym == '|' && counter != 1)
		u->i_count = 0;
}

int	ft_checkkeysym(char *buf, t_utils *u)
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
	ft_checkkeysym_assist(sym, counter, u, buf);
	u->i_keyshift = i;
	return (i);
}

int	ft_findrange(char *buf, int start, int end)
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
