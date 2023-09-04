/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:11:16 by halaqoh           #+#    #+#             */
/*   Updated: 2021/11/08 16:12:19 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		k;

	k = 0;
	dup = (char *) malloc(len(src) + 1);
	if (!dup)
		return (0);
	while (k < len(src))
	{
		dup[k] = src[k];
		k++;
	}
	dup[k] = '\0';
	return (dup);
}
