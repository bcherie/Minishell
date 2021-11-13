#include "minishell.h"

int	BUFFER_SIZE = 50;

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		new[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2) && j != ft_strlen(s1) + ft_strlen(s2))
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}

int		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		x;
	int		i;

	x = 0;
	i = 0;
	while (src[x] != '\0')
		x++;
	dest = (char *)malloc(sizeof(*dest) * (x + 1));
	if (dest == NULL)
		return (NULL);
	while (i <= x)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		a;

	a = 0;
	while (src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

char	*rem(char **res, char **line)
{
	char	*ptr;
	char	*t;

	ptr = NULL;
	*line = ft_strdup("");
	if (*res != NULL)
	{
		if ((ptr = ft_strchr(*res, '\n')))
		{
			*ptr = '\0';
			t = *line;
			*line = ft_strdup(*res);
			free(t);
			ft_strcpy(*res, ++ptr);
		}
		else
		{
			t = *line;
			*line = ft_strdup(*res);
			free(t);
			free(*res);
			*res = NULL;
		}
	}
	return (ptr);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE];
	int			num;
	char		*k;
	static char	*res;
	char		*t;

	num = 1;
	if (!line || BUFFER_SIZE <= 0 || fd < 0 || read(fd, buf, 0) == -1)
		return (-1);
	k = rem(&res, line);
	while (!k && (num = read(fd, buf, BUFFER_SIZE)))
	{
		buf[num] = '\0';
		if ((k = ft_strchr(buf, '\n')))
		{
			*k = '\0';
			k++;
			res = ft_strdup(k);
		}
		t = *line;
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
		free(t);
	}
	return ((!num) ? 0 : 1);
}

