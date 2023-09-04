/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_justchek.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 13:56:00 by halaqoh           #+#    #+#             */
/*   Updated: 2023/01/08 01:52:39 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_set_map(t_justm *map, char *line, int fd)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < map->nbline)
	{
		line = get_next_line(fd);
		map->map[i] = malloc(map->nbcol + 1);
		j = 0;
		while (line[j])
		{
			map->map[i][j] = line[j];
			j++;
		}
		j--;
		while (j < map->nbcol)
		{
			map->map[i][j] = ' ';
			if (j + 1 == map->nbcol)
				map->map[i][j] = '\n';
			j++;
		}
		map->map[i++][j] = '\0';
		free(line);
	}
}

void	ft_map(t_justm *map, char *mapfile, int skip)
{
	int		fd;
	int		i;
	char	*line;

	map->map = malloc(sizeof(char *) * (map->nbline + 1));
	map->map[map->nbline] = NULL;
	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		ft_error("file error :/ ");
	i = -1;
	while (++i < skip)
	{
		line = get_next_line(fd);
		free(line);
	}
	ft_set_map(map, line, fd);
}

void	ft_justnorm(t_justm *map, int i, int j)
{
	if (map->map[i][j] == 'N' || map->map[i][j] == 'S' \
	|| map->map[i][j] == 'E' || map->map[i][j] == 'W' )
		map->nswe++;
	if (map->map[i][j] == ' ' && (map->map[i + 1][j] == '0' \
	|| map->map[i + 1][j] == 'N' || map->map[i + 1][j] == 'S' \
	|| map->map[i + 1][j] == 'W' || map->map[i + 1][j] == 'E'))
		ft_error("error in map \n");
	if (map->map[i][j] == ' ' && (map->map[i - 1][j] == '0' \
	|| map->map[i - 1][j] == 'N' || map->map[i - 1][j] == 'S' \
	|| map->map[i - 1][j] == 'W' || map->map[i - 1][j] == 'E'))
		ft_error("error in map \n");
	if (map->map[i][j] == ' ' && (map->map[i][j + 1] == '0' \
	|| map->map[i][j + 1] == 'N' || map->map[i][j + 1] == 'S' \
	|| map->map[i][j + 1] == 'W' || map->map[i][j + 1] == 'E'))
		ft_error("error in map \n");
	if (j != 0 && map->map[i][j] == ' ' && (map->map[i][j - 1] == '0' \
	|| map->map[i][j - 1] == 'N' || map->map[i][j - 1] == 'S' \
	|| map->map[i][j - 1] == 'W' || map->map[i][j - 1] == 'E'))
		ft_error("error in map \n");
}

void	ft_checkspace(t_justm *map)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	map->nswe = 0;
	while (map->map[0][j] != '\n')
	{
		if (map->map[0][j] == ' ' && (map->map[1][j] == '0' \
		|| map->map[1][j] == 'N' || map->map[1][j] == 'S' \
		|| map->map[1][j] == 'W' || map->map[1][j] == 'E'))
			ft_error("error map in \n");
		j++;
	}
	while (i < map->nbline - 1)
	{
		j = 0;
		while (map->map[i][j] != '\n')
		{
			ft_justnorm(map, i, j);
			j++;
		}
		i++;
	}
}

void	freeroma(char **roma)
{
	free(roma[0]);
	free(roma[1]);
	free(roma[2]);
	free(roma);
}
