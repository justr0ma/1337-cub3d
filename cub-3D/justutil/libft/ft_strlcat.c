/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:49:59 by halaqoh           #+#    #+#             */
/*   Updated: 2021/11/14 18:13:31 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s;
	size_t	d;
	size_t	i;
	size_t	size;

	d = 0;
	i = 0;
	while (dst[d])
		d++;
	s = 0;
	while (src[s])
		s++;
	if (dstsize <= d)
		return (s + dstsize);
	size = (dstsize - 1) - d;
	while (size-- && src[i])
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	return (s + d);
}
