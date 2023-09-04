/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:54:19 by halaqoh           #+#    #+#             */
/*   Updated: 2021/11/14 17:00:35 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*ss1;
	char	*ss2;
	int		b;
	int		a;

	b = 0;
	a = 0;
	ss1 = (char *)s1;
	ss2 = (char *)s2;
	if (!s1 || !s2)
		return (NULL);
	join = (char *) malloc(ft_strlen(ss1) + ft_strlen(ss2) + 1);
	if (!join)
		return (0);
	while (ss1[a])
	{
		join[a] = ss1[a];
		a++;
	}
	while (ss2[b])
		join[a++] = ss2[b++];
	join[a] = '\0';
	return (join);
}
