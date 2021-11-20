/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 01:33:33 by droro             #+#    #+#             */
/*   Updated: 2021/11/21 01:33:34 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredok(t_tokens *tok)
{
	int		i;
	char	*keyword;
	char	*line;

	i = 0;
	// line = (char *)malloc(sizeof(char *));
	keyword = tok->tmp_in[0];
	if (tok->flag_l == 2)
	{
		while (1)
		{
			line = readline("> ");
			if (ft_strlen(line) > 0)
			{
				while (*line)
				{
					if (ft_strncmp(line, keyword, ft_strlen(line)) == 0)
						exit(0);
					(*line)++;
				}
			}
		}
	}
}

void	redir_flag_1(t_tokens *tok)
{
	tok->i = 0;
	tok->j = 0;
	tok->tmp_out = (char **)malloc(sizeof(char *));
	if (tok->out_n != 0)
	{
		while (tok->out_redir[tok->i] != NULL)
		{
			if (*tok->out_redir[tok->i] != 'r' && \
				*tok->out_redir[tok->i] != 'R')
			{
				tok->tmp_out[tok->j] = tok->out_redir[tok->i];
				tok->j++;
			}
			else
			{
				if (*tok->out_redir[tok->i] == 'r')
					tok->flag_r = 1;
				else if (*tok->out_redir[tok->i] == 'R')
					tok->flag_r = 2;
			}
			tok->i++;
		}
	}
	redir_flag_2(tok);
}

void	redir_flag_2(t_tokens *tok)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	tok->tmp_in = (char **)malloc(sizeof(char *));
	if (tok->inp_n != 0)
	{
		while (tok->in_redir[i] != NULL)
		{
			if (*tok->in_redir[i] != 'l' && *tok->in_redir[i] != 'L')
			{
				tok->tmp_in[j] = tok->in_redir[i];
				j++;
			}
			else
			{
				if (*tok->in_redir[i] == 'l')
					tok->flag_l = 1;
				else if (*tok->in_redir[i] == 'L')
					tok->flag_l = 2;
			}
			i++;
		}
	}
}

void	ft_check_redirect(t_tokens *tok)
{
	int	j;
	int	fd;
	int	old_fd;

	j = 0;
	while (j != tok->out_n)
	{
		if (tok->flag_r == 1)
			fd = open(tok->tmp_out[j], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (tok->flag_r == 2)
			fd = open(tok->tmp_out[j], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd < 0)
		{
			printf ("error\n");
			j = -1;
			break ;
		}
		old_fd = dup(fd);
		dup2(old_fd, 1);
		close(fd);
		j++;
	}
	if (j == -1)
		return ;
	ft_check_redirect_2(tok, fd, old_fd);
}

void	ft_check_redirect_2(t_tokens *tok, int fd, int old_fd)
{
	int	j;

	j = 0;
	while (j != tok->inp_n)
	{
		if (tok->flag_l == 1)
			fd = open(tok->tmp_in[j], O_RDONLY, 0644);
		else if (tok->flag_l == 2)
			fd = open(tok->tmp_in[j], O_RDONLY, 0644);
		if (fd < 0)
		{
			printf ("error\n");
		}
		old_fd = dup(fd);
		dup2(old_fd, 0);
		close(fd);
		j++;
	}
}
