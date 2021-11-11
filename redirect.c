#include "minishell.h"
#include <fcntl.h>
//кейсы: export gggg > testf создаст файлб но не запишет
// echo 55 > > file.txt - doesn't work in our minishell
void	ft_check_redirect(t_all *mass, t_tokens *tok)
{
	// int		fd;
	int		count;
	int		i;
	int		j;
	char	*str;
	int		index[100];
	char	*arg;
	size_t len;
	// char	*tmp;
	tok = NULL;
	len = 0;
	int	*ptr1;
	int	*ptr2;

	i = 0;
	j = 0;
	count = 0;
	printf("buf: %s\n", mass->buf);
	str = ft_strdup(mass->buf);
	//прописать пропуск "> > >"
	while (str[i])
	{
		if (str[i] == '>')
		{
			index[j] = i;
			count++;
			j++;
		}
		i++;
	}
	// printf("index: %d\n", index[0]);
	// printf("index1: %d\n", index[1]);
	// printf("index2: %d\n", index[2]);
	// while (str[i] && )
	// printf("j: %d\n", index[j]);
	// printf("j + 1: %d\n", index[j] + 1);
	ptr1 = &index[0];
	ptr2 = ptr1++;
	// printf("ptr1: %d\n", *ptr1);
	// printf("ptr2: %d\n", *ptr2);
	len = *ptr1 - *ptr2;
	printf("len: %zu\n", len);
	arg = ft_substr(str, index[0], len);
	printf("arg: %s\n", arg);
}
