/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:04:54 by abel-bou          #+#    #+#             */
/*   Updated: 2023/01/08 01:37:22 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_mouse(int x, int y, t_justm *t)
{
	if (x < WINDOW_WIDTH / 2 - 4 && x > 0 && x < WINDOW_WIDTH
		&& y > 0 && y < WINDOW_HEIGHT)
		keyft(123, t);
	else if (x > WINDOW_WIDTH / 2 + 4 && x > 0 && x < WINDOW_WIDTH
		&& y > 0 && y < WINDOW_HEIGHT)
		keyft(124, t);
	return (0);
}

void	ft_von(char	**roma, char *lcolor)
{
	int	i;
	int	j;
	int	com;

	i = 0;
	com = 0;
	while (lcolor[i])
	{
		if (lcolor[i] == ',')
			com++;
		if (com > 2)
			ft_error("error in ',' \n");
		i++;
	}
	i = -1;
	while (roma[++i])
	{
		j = -1;
		while (roma[i][++j])
			if ((roma[i][j] < '0' || roma[i][j] > '9') && roma[i][j] != '\n')
				ft_error("error in color \n");
	}
	if (i != 3)
		ft_error("error in map\n");
}
