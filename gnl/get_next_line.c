/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:14:02 by bcherie           #+#    #+#             */
/*   Updated: 2020/12/25 11:20:52 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char		buf[BUFFER_SIZE + 1];
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
// 	int    main()
// {
//     char *line;
//  	int i = 0;
//
//     int fd = open("test.txt", O_RDONLY);
//     while ((i = get_next_line(fd, &line)))
//  	{
//      	printf("line: %s\n", line);
//  		printf("return: %d\n", i);
// 		free(line);
//  	}
//  	printf("line: %s\n", line);
//  	printf("return: %d\n", i);
// 	free(line);
//     return (0);
//  }

