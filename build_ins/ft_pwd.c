/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droro <droro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:56:22 by droro             #+#    #+#             */
/*   Updated: 2021/11/16 22:56:23 by droro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_pwd(int type)
{
	char	*path;
	char	*buffer;

	buffer = NULL;
	path = getcwd(buffer, sizeof(buffer));
	if (type == 1)
		printf("%s\n", path);
	return (path);
}
