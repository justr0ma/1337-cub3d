/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chek.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 11:04:19 by halaqoh           #+#    #+#             */
/*   Updated: 2023/01/08 01:39:48 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*texter(char *maptexter)
{
	char	*ntexter;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!maptexter)
		ft_error("error in map texter\n");
	while (maptexter[i] && maptexter[i] == ' ')
		i++;
	ntexter = malloc(ft_strlen(maptexter + i));
	if (ntexter == NULL)
		ft_error("error in texter\n");
	while (maptexter[i] && maptexter[i] != '\n')
	{
		ntexter[j] = maptexter[i];
		i++;
		j++;
	}
	ntexter[j] = '\0';
	free(maptexter);
	return (ntexter);
}

void	ft_texterpath(t_justm *map)
{
	int		fdtexter;

	map->no = texter(map->no);
	fdtexter = open(map->no, O_RDONLY);
	if (fdtexter < 0)
		ft_error("file error nnn :/ ");
	map->so = texter(map->so);
	fdtexter = open(map->so, O_RDONLY);
	if (fdtexter < 0)
		ft_error("file error sss :/ ");
	map->we = texter(map->we);
	fdtexter = open(map->we, O_RDONLY);
	if (fdtexter < 0)
		ft_error("file error wwww:/ ");
	map->ea = texter(map->ea);
	fdtexter = open(map->ea, O_RDONLY);
	if (fdtexter < 0)
		ft_error("file error eeee:/ ");
}

void	s_chek(t_justm *map, int skip, char *line, char *mapfile)
{
	while (!ft_strncmp(line, "\n", ft_strlen(line)))
	{
		free(line);
		line = get_next_line(map->fd);
		skip++;
	}
	ft_chekmap(line, map, map->fd);
	ft_map(map, mapfile, skip);
	ft_checkspace(map);
	if (map->nswe != 1)
		ft_error("error in map\n");
	ft_texterpath(map);
}

void	ft_chekmapfile(char *mapfile, t_justm *map)
{
	int		skip;
	char	*line;

	skip = 0;
	map->element_b_map = 0;
	map->fd = open(mapfile, O_RDONLY);
	if (map->fd < 0)
		ft_error("file error :/ ");
	line = get_next_line(map->fd);
	while (line && map->element_b_map != 6)
	{
		if (ft_strncmp(line, "\n", ft_strlen(line)) && map->element_b_map != 6)
		{
			if ((line[0] != 'N' && line[0] != 'S' && line[0] != 'W' && line[0] \
			!= 'E' && line[0] != 'F' && line[0] != 'C'))
				if (map->element_b_map != 6)
					ft_error("error\nin the map");
			ft_check_textur(line, map);
		}
		free(line);
		line = get_next_line(map->fd);
		skip++;
	}
	s_chek(map, skip, line, mapfile);
}

void	ft_checktexter_f(t_justm *map, char *lcolor, int i)
{
	int		com;
	char	**roma;

	com = 0;
	while (lcolor[i] && lcolor[i] == ' ')
		i++;
	roma = ft_split(lcolor + i, ',');
	ft_von(roma, lcolor);
	map->f[0] = ft_atoi(roma[0]);
	map->f[1] = ft_atoi(roma[1]);
	map->f[2] = ft_atoi(roma[2]);
	if (map->f[0] < 0 || map->f[0] > 255 || map->f[1] < 0 || \
	map->f[1] > 255 || map->f[2] < 0 || map->f[2] > 255)
		ft_error("Error in Floor\n");
	freeroma(roma);
	map->element_b_map++;
}
