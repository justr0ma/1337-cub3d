/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:28:53 by abel-bou          #+#    #+#             */
/*   Updated: 2023/01/08 01:06:21 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_key02(t_justm *t, int keycode, double i, double j)
{
	if (keycode == 0)
	{
		i = (t->px + cos(t->pa - M_PI / 2) * MOVE_SPEED);
		j = (t->py + sin(t->pa - M_PI / 2) * MOVE_SPEED);
		if (t->map[(int)j / TILE_SIZE][(int)i / TILE_SIZE] == '0')
		{
			t->px += cos(t->pa - M_PI / 2) * MOVE_SPEED;
			t->py += sin(t->pa - M_PI / 2) * MOVE_SPEED;
		}
	}
	if (keycode == 2)
	{
		i = (t->px + cos(t->pa + M_PI / 2) * MOVE_SPEED);
		j = (t->py + sin(t->pa + M_PI / 2) * MOVE_SPEED);
		if (t->map[(int)j / TILE_SIZE][(int)i / TILE_SIZE] == '0')
		{
			t->px += cos(t->pa + M_PI / 2) * MOVE_SPEED;
			t->py += sin(t->pa + M_PI / 2) * MOVE_SPEED;
		}
	}
}

void	ft_key1(t_justm *t, int keycode, int i, int j)
{
	if (keycode == 1)
	{
		i = (t->px - cos(t->pa) * MOVE_SPEED);
		j = (t->py - sin(t->pa) * MOVE_SPEED);
		if (t->map[(int)j / TILE_SIZE][(int)i / TILE_SIZE] == '0')
		{
			t->px -= cos(t->pa) * MOVE_SPEED;
			t->py -= sin(t->pa) * MOVE_SPEED;
		}
	}
}

int	keyft(int keycode, t_justm *t)
{
	double	i;
	double	j;

	i = 0;
	j = 0;
	key_fov(t, keycode);
	ft_key02(t, keycode, i, j);
	ft_key1(t, keycode, i, j);
	if (keycode == 13)
	{
		i = (t->px + cos(t->pa) * MOVE_SPEED);
		j = (t->py + sin(t->pa) * MOVE_SPEED);
		if (t->map[(int)j / TILE_SIZE][(int)i / TILE_SIZE] == '0' \
		&& t->distance[WINDOW_WIDTH / 2] > TILE_SIZE / 2)
		{
			t->px += cos(t->pa) * MOVE_SPEED;
			t->py += sin(t->pa) * MOVE_SPEED;
		}
	}
	if (keycode == 53)
		exit(1);
	destroy_img(t);
	return (0);
}

void	ft_init(t_justm *map)
{
	int	i;

	i = 0;
	map->no = NULL;
	map->so = NULL;
	map->ea = NULL;
	map->we = NULL;
	map->distance = malloc(sizeof(double) * WINDOW_WIDTH);
	map->hx = malloc(sizeof(double) * WINDOW_WIDTH);
	map->vy = malloc(sizeof(double) * WINDOW_WIDTH);
	map->xwall = malloc(sizeof(double) * WINDOW_WIDTH);
	map->ywall = malloc(sizeof(double) * WINDOW_WIDTH);
	while (i < 3)
	{
		map->f[i] = 0;
		map->c[i] = 0;
		i++;
	}
	map->fov = 60 * (M_PI / 180);
}

int	main(int argc, char **argv)
{
	t_justm	*map;

	map = malloc(sizeof(t_justm));
	ft_init(map);
	if (argc == 2 && ft_chr(argv[1] + (len(argv[1]) - 4)))
	{
		ft_chekmapfile(argv[1], map);
		just_initfov(map);
		map->mlx = mlx_init();
		map->win = mlx_new_window(map->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "r");
		map->img = mlx_new_image(map->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
		map->addr = mlx_get_data_addr(map->img, &map->bits_per_pixel, \
		&map->line_length, &map->endian);
		open_file(map);
		mapping(map);
		mlx_hook(map->win, 17, 0, clos, map);
		mlx_hook(map->win, 2, 0, keyft, map);
		mlx_hook(map->win, 6, 0, ft_mouse, map);
		mlx_loop(map->mlx);
	}
	else
		perror("Error");
}
