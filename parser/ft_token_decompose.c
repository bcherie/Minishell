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

static int	ft_pretoken_check(char *string, int start, int end)
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

void	ft_pretoken_count(t_all *mass)
{
	int	count;
	int	i;
	int	checker;

	count = 0;
	i = 0;
	checker = 1;
	while (checker == 1)
	{
		if (mass->buf[mass->sub_indx[i]] == '\0' || \
		mass->buf[mass->sub_indx[i + 1]] == '\0')
			checker = 0;
		else
		{
			count++;
			i = i + 2;
		}
	}
	mass->number_of_pretokens = count;
}

void	ft_init_utils_struct(t_utils *u)
{
	u->iter = 0;
	u->flag_find_command = 1;
	u->flag_token_join = 0;
	u->flag_find_file = 0;
	u->flag_dollar_on = 1;
	u->i_keyshift = 0;
	u->i_count = 0;
	u->st = 0;
	u->n_st = 0;
	u->end = 0;
	u->n_end = 0;
}

static int	ft_token_decompose_nonquotes(t_all *mass, t_tokens *tm, t_utils *u)
{
	if (fpf_strchr("<>|", mass->buf[u->n_st]))
	{
		ft_checkkeysym(mass->buf, u);
		if (u->i_count <= 0)
			return (-1);
		else
		{
			tm = ft_token_add(mass);
			ft_token_keys(mass->buf[u->n_st], u->i_count, tm);
			if (mass->buf[u->n_st] == '|')
				u->flag_find_command = 1;
			else
				u->flag_find_file = 1;
			u->n_st = u->i_keyshift;
		}
	}
	else
	{
		ft_token_join_test(mass, u);
		u->n_end = ft_findrange(mass->buf, u->n_st, u->end);
		u->n_end = ft_findcommand(mass->buf, u->n_st, u->n_end);
		if (ft_token_former(mass, u) == 0)
			return (-1);
	}
	return (1);
}

static int	ft_token_decompose_quotes(t_all *mass, t_utils *u)
{
	ft_token_join_test(mass, u);
	if (mass->buf[u->n_st] == 39)
		u->flag_dollar_on = 0;
	u->n_st++;
	u->n_end--;
	if (ft_token_former(mass, u) == 0)
		return (-1);
	u->n_st++;
	u->flag_dollar_on = 1;
	return (1);
}

int	ft_token_decompose(t_all *mass)
{
	t_tokens	*tmp_token;
	t_utils		u;
	int			i;
	int			ret;

	i = 0;
	ret = 1;
	tmp_token = NULL;
	ft_pretoken_count(mass);
	ft_init_utils_struct(&u);
	while (ret > 0 && u.iter < mass->number_of_pretokens)
	{
		u.st = mass->sub_indx[i];
		u.end = mass->sub_indx[i + 1];
		u.n_st = u.st;
		u.n_end = u.end;
		ret = ft_pretoken_check(mass->buf, u.st, u.end);
		while (u.n_st <= u.end)
		{
			if (mass->buf[u.n_st] == ' ')
				u.n_st = ft_spacekill(mass->buf, u.n_st, u.end);
			else
			{
				if (ret == 2)
					ft_token_decompose_nonquotes(mass, tmp_token, &u);
				else if (ret == 1)
					ft_token_decompose_quotes(mass, &u);
			}
		}
		i = i + 2;
		u.iter++;
	}
	return (0);
}
