/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:52:44 by halaqoh           #+#    #+#             */
/*   Updated: 2021/11/07 18:07:31 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		b;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	b = 0;
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[b])
		{
			while (needle[b] && needle[b] == haystack[i + b] && (b + i) < len)
			{
				if (needle[b + 1] == '\0')
					return ((char *)haystack + i);
				b++;
			}
		}
		b = 0;
		i++;
	}
	return (0);
}
