/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:08:13 by halaqoh           #+#    #+#             */
/*   Updated: 2021/11/15 12:10:42 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_word(const char *s, char c)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i + 1])
				i++;
			a++;
		}
		i++;
	}
	return (a);
}

char	*ft_strndup(char *s, int n)
{
	int		k;
	char	*str;

	k = 0;
	str = malloc(n + 1);
	if (!str)
		return (0);
	while (k < n)
	{
		str[k] = s[k];
		k++;
	}
	str[k] = '\0';
	return (str);
}

char	**mn_split(char **str, const char *s, const char c)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	a = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i + j] != c && s[i + j])
				j++;
			str[a] = ft_strndup((char *) s + i, j);
			a++;
			i += j - 1;
		}
		i++;
	}
	str[a] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		nb_word;
	char	**str_split;

	if (!s)
		return (0);
	nb_word = ft_count_word(s, c);
	str_split = malloc((nb_word + 1) * (sizeof(char *)));
	if (!str_split)
		return (0);
	str_split = mn_split(str_split, s, c);
	return (str_split);
}
