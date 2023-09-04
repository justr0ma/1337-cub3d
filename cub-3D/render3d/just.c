/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:09:28 by halaqoh           #+#    #+#             */
/*   Updated: 2023/01/07 21:49:19 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	get_color_texture(t_texture *tex, int i, int j, int s_wall)
{
	int		x;
	int		y;
	char	*color;

	x = i % 64;
	y = (j * 64 / s_wall) % 64;
	color = tex->addr + (y * tex->line_length) + \
	(x * (tex->bits_per_pixel / 8));
	return (*(int *)color);
}

void	f_wall(t_justm *t, int i, double wallheight)
{
	int	j;
	int	color;

	j = 0;
	while (j < wallheight)
	{
		if (t->hx[i] == (double)1 && t->px > t->xwall[i])
			color = get_color_texture(t->wea, t->ywall[i], j, wallheight);
		if (t->hx[i] == (double)1 && t->px < t->xwall[i])
			color = get_color_texture(t->eas, t->ywall[i], j, wallheight);
		if (t->vy[i] == (double)1 && t->py > t->ywall[i])
			color = get_color_texture(t->nor, t->xwall[i], j, wallheight);
		if (t->vy[i] == (double)1 && t->py < t->ywall[i])
			color = get_color_texture(t->sou, t->xwall[i], j, wallheight);
		my_mlx_pixel_put(t, i, (j / 2 + (WINDOW_HEIGHT / 2) - \
		(wallheight / 2) / 2), color);
		j++;
	}
}

void	render3d(t_justm *t)
{
	int		i;
	double	distance_wall;
	double	wallheight;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		distance_wall = ((WINDOW_WIDTH) / 2) / tan(t->fov) / 2;
		wallheight = ((WINDOW_HEIGHT) / t->distance[i]) * distance_wall;
		f_wall(t, i, wallheight);
		i++;
	}
}

void	just_ceil_floor(t_justm *t)
{
	int	a;
	int	b;

	a = 0;
	while (a < WINDOW_WIDTH)
	{
		b = 0;
		while (b < WINDOW_HEIGHT / 2)
		{
			my_mlx_pixel_put(t, a, b, t->color_c);
			b++;
		}
		a++;
	}
	a = 0;
	while (a < WINDOW_WIDTH)
	{
		b = 0;
		while (b < WINDOW_HEIGHT / 2)
		{
			my_mlx_pixel_put(t, a, WINDOW_HEIGHT / 2 + b, t->color_f);
			b++;
		}
		a++;
	}
}

void	init_p(t_justm *t, int x, int y)
{
	t->px = x * TILE_SIZE + (TILE_SIZE / 2);
	t->py = y * TILE_SIZE + (TILE_SIZE / 2);
	if (t->map[y][x] == 'N')
		t->pa = 3 * M_PI / 2;
	else if (t->map[y][x] == 'S')
		t->pa = M_PI / 2;
	else if (t->map[y][x] == 'E')
		t->pa = 2 * M_PI;
	else if (t->map[y][x] == 'W')
		t->pa = M_PI;
	t->map[y][x] = '0';
}
