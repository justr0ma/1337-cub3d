/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:33:56 by halaqoh           #+#    #+#             */
/*   Updated: 2021/11/13 12:34:06 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbchar(long n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n >= 1)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*n_s(char *str, long n, int len)
{
	int	isneg;

	if (n != 0)
		str = malloc(len + 1);
	else
		return (ft_strdup("0"));
	if (!str)
		return (0);
	isneg = 0;
	if (n < 0)
	{
		isneg++;
		n = -n;
	}
	str[len] = '\0';
	while (--len)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	if (isneg == 1)
		str[0] = '-';
	else
		str[0] = (n % 10) + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = nbchar((long)n);
	str = 0;
	str = n_s(str, (long)n, len);
	if (!str)
		return (0);
	return (str);
}
