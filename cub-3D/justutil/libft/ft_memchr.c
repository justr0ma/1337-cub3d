/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:25:56 by halaqoh           #+#    #+#             */
/*   Updated: 2021/11/06 21:31:25 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ss;
	size_t			i;
	unsigned char	cc;

	ss = (unsigned char *)s;
	cc = (unsigned char )c;
	i = 0;
	while (i < n)
	{
		if (ss[i] == cc)
			return ((unsigned char *)s + i);
		i++;
	}
	return (0);
}
