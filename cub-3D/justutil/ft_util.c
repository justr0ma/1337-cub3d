/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:45:33 by halaqoh           #+#    #+#             */
/*   Updated: 2023/01/06 20:59:06 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	clos(void)
{
	exit(1);
	return (0);
}

size_t	len(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

int	ft_chr(char *str)
{
	int		i;
	char	*ber;

	ber = ".cub";
	i = 0;
	while (str[i])
	{
		if (str[i] != ber[i])
			return (0);
		i++;
	}
	return (1);
}
