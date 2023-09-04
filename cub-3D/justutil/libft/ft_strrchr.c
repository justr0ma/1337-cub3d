/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:07:50 by halaqoh           #+#    #+#             */
/*   Updated: 2021/11/07 18:10:11 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		b;
	char	*l;

	i = 0;
	b = -1;
	l = (char *)s;
	while (l[i])
	{
		if (l[i] == (char)c)
			b = i;
		i++;
	}
	if (c == '\0')
		return (l + i);
	if (b >= 0)
		return (l + b);
	return (0);
}
