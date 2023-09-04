/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:41:14 by halaqoh           #+#    #+#             */
/*   Updated: 2021/11/30 23:03:07 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ds;
	char	*sr;
	size_t	i;

	ds = (char *) dst;
	sr = (char *) src;
	i = 0;
	if (ds > sr)
	{
		while (len--)
		{
			ds[len] = sr[len];
		}
	}
	else if (sr > ds)
	{
		while (len--)
		{
			ds[i] = sr[i];
			i++;
		}
	}
	return (dst);
}
