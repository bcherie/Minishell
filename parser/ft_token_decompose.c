#include "../minishell.h"

int	ft_space_cleaner(char *buf, int start, int end)
{
	int	new_start;

	new_start = 0;
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

int	ft_command_check(char *buf, int start, int end)
{
	int	len;

	len = 0;
	len = end - start + 1;
	
}

int	ft_token_decompose(t_all *mass)
{
	char	*buf;
	char	*sub_buf;
	int		st;
	int 	end;
	int		i;

	sub_buf = NULL;
	buf = mass->buf;
	i = 0;
	st = ft_space_cleaner(buf, mass->substr_inds[i], mass->substr_inds[i + 1]);
	i += 2;

}