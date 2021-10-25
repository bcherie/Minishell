#include "../minishell.h"

static void	simple_tr(const char *str, long long *z)
{
	while (*str >= '0' && *str <= '9')
	{
		(*z) = (*z) * 10 + (*str - '0');
		str++;
	}
}

static int all_digit(const char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_ms_atoi_checksyms(const char *str)
{
	int		len;
	char	*l;
	int		i;
		
	l = "9223372036854775807";
	len = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] == '0')
		i++;
	if (all_digit(&str[i]) == 0)
		return (0);
	len = ft_strlen(&str[i]);
	if (len > 19)
		return (0);
	else if (len == 19)
	{
		if (ft_strncmp(l, &str[i], 19) >= 0)
			return (1);
		return (0);
	}
	return (1);
}

long long	ft_atolonglong(const char *str)
{
	int				sign;
	long long		output_num;

	output_num = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && *str == '0')
		str++;
	simple_tr(str, &output_num);
	return (output_num * sign);
}
