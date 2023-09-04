/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_far_from_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:45:37 by halaqoh           #+#    #+#             */
/*   Updated: 2023/01/07 22:08:18 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	open_img_texture(t_justm *t, t_texture *tex, char *path)
{
	tex->img_text = mlx_xpm_file_to_image(t->mlx, path, \
	&tex->width_img, &tex->height_img);
	if (!tex->img_text)
		ft_error("Error in img\n");
	tex->addr = mlx_get_data_addr(tex->img_text, \
	&tex->bits_per_pixel, &tex->line_length, &tex->endian);
}

void	open_file(t_justm *t)
{
	t->nor = malloc(sizeof(t_texture));
	t->sou = malloc(sizeof(t_texture));
	t->wea = malloc(sizeof(t_texture));
	t->eas = malloc(sizeof(t_texture));
	open_img_texture(t, t->nor, t->no);
	open_img_texture(t, t->sou, t->so);
	open_img_texture(t, t->wea, t->we);
	open_img_texture(t, t->eas, t->ea);
}

void	rays(t_justm *t)
{
	int		i;
	double	ca;

	i = 0;
	t->rayangl = t->pa - (t->fov / 2);
	while (i < WINDOW_WIDTH)
	{
		ddaline(t->px + cos(t->rayangl) \
		, t->py + sin(t->rayangl), t, i);
		ca = t->pa - t->rayangl;
		t->distance[i] *= cos(ca);
		t->rayangl += t->fov / WINDOW_WIDTH;
		i++;
	}
}

void	mapping(t_justm *t)
{
	t->color_f = (t->f[2] + t->f[1] * 256 + t->f[0] * 256 * 256);
	t->color_c = (t->c[2] + t->c[1] * 256 + t->c[0] * 256 * 256);
	just_ceil_floor(t);
	rays(t);
	render3d(t);
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
}

void	key_fov(t_justm *t, int keycode)
{
	if (keycode == 123)
	{
		t->pa -= ROTATION_SPEED;
		if (t->pa < 0)
			t->pa = 2 * M_PI;
	}
	else if (keycode == 124)
	{
		t->pa += ROTATION_SPEED;
		if (t->pa > 2 * M_PI)
			t->pa -= 2 * M_PI;
	}
}
