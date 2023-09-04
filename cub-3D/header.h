/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:26:25 by halaqoh           #+#    #+#             */
/*   Updated: 2023/01/08 01:38:17 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdarg.h>
# include "./justutil/libft/libft.h"
# include <math.h>

# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 720
# define ROTATION_SPEED 0.2
# define MOVE_SPEED 10
# define TILE_SIZE 64

typedef struct s_img_texture
{
	char	*addr;
	void	*img_text;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width_img;
	int		height_img;
}	t_texture;

typedef struct a
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			f[3];
	int			c[3];
	int			color_f;
	int			color_c;
	int			element_b_map;
	char		**map;
	int			nbline;
	double		nbcol;

	double		x;
	double		y;
	double		px;
	double		py;

	double		pdy;
	double		pa;
	double		rayangl;
	int			nswe;

	t_texture	*nor;
	t_texture	*sou;
	t_texture	*wea;
	t_texture	*eas;

	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width_img;
	int			height_img;

	double		*distance;
	double		fov;

	double		*hx;
	double		*vy;
	double		*xwall;
	double		*ywall;
	int			*texter;
	int			fd;

	double		steps;
	double		old_y;
	double		old_x;
	double		dx;
	double		dy;
	double		xinc;
	double		yinc;
}t_justm;

int		ft_chr(char *str);
void	ft_chekmapfile(char *mapfile, t_justm *map);
char	*get_next_line(int fd);
size_t	len(char *src);
int		clos(void);
void	ft_error(char *msg);
int		ft_chr(char *str);
char	*texter(char *maptexter);
void	ft_texterpath(t_justm *map);
void	ft_check_textur(char *line, t_justm *map);
void	ft_chekmap(char *line, t_justm *map, int fd);
void	ft_map(t_justm *map, char *mapfile, int skip);
void	ft_checkspace(t_justm *map);
void	ft_checktexter_f(t_justm *map, char *lcolor, int i);
void	render3d(t_justm *t);
void	mapping(t_justm *t);
void	just_ceil_floor(t_justm *t);
void	init_p(t_justm *t, int x, int y);
void	rays(t_justm *t);
void	key_fov(t_justm *t, int keycode);

void	my_mlx_pixel_put(t_justm *data, int x, int y, int color);
void	ddaline(double x1, double y1, t_justm *t, int i);

void	just_initfov(t_justm *t);

void	open_img_texture(t_justm *t, t_texture *tex, char *path);
void	open_file(t_justm *t);
int		ft_mouse(int x, int y, t_justm *t);
void	destroy_img(t_justm *t);
void	freeroma(char **roma);
int		keyft(int keycode, t_justm *t);
void	ft_von(char	**roma, char *lcolor);
#endif