/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chekmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:32:02 by halaqoh           #+#    #+#             */
/*   Updated: 2023/01/08 01:50:36 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_checktexter_c(t_justm *map, char *lcolor, int i)
{
	char	**roma;

	while (lcolor[i] && lcolor[i] == ' ')
		i++;
	roma = ft_split(lcolor + i, ',');
	ft_von(roma, lcolor);
	map->c[0] = ft_atoi(roma[0]);
	map->c[1] = ft_atoi(roma[1]);
	map->c[2] = ft_atoi(roma[2]);
	if (map->c[0] < 0 || map->c[0] > 255 || map->c[1] < 0 \
	|| map->c[1] > 255 || map->c[2] < 0 || map->c[2] > 255)
		ft_error("Error in Ceil\n");
	freeroma(roma);
	map->element_b_map++;
}

void	ft_check_textur(char *line, t_justm *map)
{
	if (!ft_strncmp(line, "NO ", 3))
		map->no = ft_strdup(ft_strchr(line, ' '));
	else if (!ft_strncmp(line, "SO ", 3))
		map->so = ft_strdup(ft_strchr(line, ' '));
	else if (!ft_strncmp(line, "WE ", 3))
		map->we = ft_strdup(ft_strchr(line, ' '));
	else if (!ft_strncmp(line, "EA ", 3))
		map->ea = ft_strdup(ft_strchr(line, ' '));
	else if (!ft_strncmp(line, "F ", 2))
		ft_checktexter_f(map, ft_strchr(line, ' '), 0);
	else if (!ft_strncmp(line, "C ", 2))
		ft_checktexter_c(map, ft_strchr(line, ' '), 0);
	else
		ft_error("error in roma");
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3) \
	|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3))
		map->element_b_map++;
}

void	ft_check_f_l_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ' && line[i] != '\n')
			ft_error("error in map\n");
		i++;
	}
}

char	*ft_check_map1(t_justm *map, char *line)
{
	size_t	i;
	int		len;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] != '1' && i != ft_strlen(line) - 1)
		ft_error("error in maphere\n");
	len = ft_strlen(line) - 1;
	while ((line[len] == ' ' || line[len] == '\n') && len > 0)
		len--;
	if (line[len] != '1' && i != ft_strlen(line) - 1)
		ft_error("error in mapfffff\n");
	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' \
		&& line[i] != 'S' && line[i] != 'W' && line[i] != 'E' \
		&& line[i] != ' ' && line[i] != '\n')
			ft_error("error in map \n");
		i++;
	}
	if (map->nbcol < ft_strlen(line))
		map->nbcol = ft_strlen(line);
	return (line);
}

void	ft_chekmap(char *line, t_justm *map, int fd)
{
	char	*lastline;

	map->nbline = 0;
	ft_check_f_l_line(line);
	map->nbcol = ft_strlen(line);
	while (line)
	{
		map->nbline++;
		if (!ft_strncmp(line, "\n", ft_strlen(line)))
			ft_error("error in map\n");
		lastline = ft_check_map1(map, line);
		line = get_next_line(fd);
		if (line)
			free(lastline);
	}
	ft_check_f_l_line(lastline);
	free(lastline);
}
