/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:23:26 by halaqoh           #+#    #+#             */
/*   Updated: 2023/01/01 14:05:13 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*ft_strdupff(char *s)
{
	char	*r;
	int		i;

	i = 0;
	while (s[i])
		i++;
	r = malloc(sizeof(char) * i + 1);
	if (!r)
		return (0);
	i = 0;
	while (s[i])
	{
		r[i] = s[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

char	*ft_strjoinff(char *s, char c)
{
	char	*r;
	int		i;

	i = 0;
	while (s[i])
		i++;
	r = malloc(sizeof(char) * i + 2);
	if (!r)
		return (NULL);
	i = 0;
	while (s[i])
	{
		r[i] = s[i];
		i++;
	}
	r[i] = c;
	r[i + 1] = '\0';
	free (s);
	return (r);
}

char	*get_next_line(int fd)
{
	char		buff;
	static char	*line;
	int			ret;
	int			i;

	i = 0;
	if (fd < 0)
		return (NULL);
	line = ft_strdupff("");
	ret = read(fd, &buff, 1);
	while (ret > 0)
	{
		line = ft_strjoinff(line, buff);
		if (buff == '\n')
			break ;
		ret = read(fd, &buff, 1);
	}
	while (line[i])
		i++;
	if (i == 0 || ret == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
