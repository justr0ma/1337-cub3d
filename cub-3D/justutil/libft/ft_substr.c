/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:41:17 by halaqoh           #+#    #+#             */
/*   Updated: 2021/11/09 11:41:32 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (s == 0)
		return (0);
	if ((len + 1) >= ft_strlen((char *)s))
		len = ft_strlen((char *)s);
	sub = (char *) malloc(len + 1);
	if (!sub)
		return (NULL);
	while (len-- > 0 && start < ft_strlen((char *)s))
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
