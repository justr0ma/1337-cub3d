/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:55:19 by halaqoh           #+#    #+#             */
/*   Updated: 2023/01/06 02:17:21 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	my_mlx_pixel_put(t_justm *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	check_x_y(t_justm *t, int x, int y, int i)
{
	if (t->map[(int)t->old_y / TILE_SIZE][(int)x / TILE_SIZE] == '1')
	{
		t->hx[i] = 1;
		t->vy[i] = 0;
	}
	else
	{
		t->hx[i] = 0;
		t->vy[i] = 1;
	}
	t->xwall[i] = x;
	t->ywall[i] = y;
	t->distance[i] = sqrt(pow((x - t->px), 2) + pow((y - t->py), 2));
}

void	ddaline(double x1, double y1, t_justm *t, int i)
{
	double	x;
	double	y;

	t->dx = x1 - t->px;
	t->dy = y1 - t->py;
	if (fabs(t->dx) > fabs(t->dy))
		t->steps = fabs(t->dx);
	else
		t->steps = fabs(t->dy);
	t->xinc = t->dx / t->steps;
	t->yinc = t->dy / t->steps;
	x = t->px;
	y = t->py;
	t->old_y = t->py;
	t->old_x = t->px;
	while (t->map[(int)y / TILE_SIZE][(int)x / TILE_SIZE] == '0')
	{
		t->old_x = x;
		t->old_y = y;
		x += t->xinc / 16;
		y += t->yinc / 16;
	}
	check_x_y(t, x, y, i);
}

void	just_initfov(t_justm *t)
{
	int	x;
	int	y;

	y = 0;
	while (t->map[y])
	{
		x = 0;
		while (t->map[y][x])
		{
			if (t->map[y][x] == 'N' || t->map[y][x] == 'S' \
			|| t->map[y][x] == 'E' || t->map[y][x] == 'W')
				init_p(t, x, y);
			x++;
		}
		y++;
	}
}

void	destroy_img(t_justm *t)
{
	mlx_destroy_image(t->mlx, t->img);
	t->img = mlx_new_image(t->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	t->addr = mlx_get_data_addr(t->img, &t->bits_per_pixel, \
		&t->line_length, &t->endian);
	mapping(t);
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
}
