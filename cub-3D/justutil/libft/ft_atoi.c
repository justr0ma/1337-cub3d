/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:04:07 by halaqoh           #+#    #+#             */
/*   Updated: 2021/11/08 12:08:21 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	signe(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		j;
	long	n;
	long	c;

	i = 0;
	j = 1;
	n = 0;
	c = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	j = signe(str[i]);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + str[i] - '0';
		if (n < c && j == -1)
			return (0);
		if (n < c)
			return (-1);
		c = n;
		i++;
	}
	return (j * n);
}
