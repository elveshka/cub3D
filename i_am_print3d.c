/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_print3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:08:15 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/28 20:11:36 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int			wall_finder(t_data *img, double c, double angle, int j)
{
	double	xx;
	double	yy;

	img->structure->player_pos->xx = \
	img->structure->player_pos->x + c * cos(angle);
	img->structure->player_pos->yy = \
	img->structure->player_pos->y + c * sin(angle);
	xx = img->structure->player_pos->xx;
	yy = img->structure->player_pos->yy;
	if (img->structure->map[(int)yy][(int)xx] == '1' \
		|| img->structure->map[(int)yy][(int)xx] == '\0' \
		|| img->structure->map[(int)yy][(int)xx] == ' ')
	{
		img->wall_d[img->structure->win_w - j] = c;
		return (1);
	}
	return (0);
}

void				print_3d(t_map *structure, t_data *img)
{
	double	c;
	int		j;
	double	angle;

	angle = structure->player_pos->player_facing - M_PI_2 / 3;
	j = 0;
	img->wall_d = malloc(sizeof(double) * img->structure->win_w);
	while (++j < structure->win_w)
	{
		angle = angle + (M_PI / 3) / structure->win_w;
		angle = correctangle(angle);
		c = 0.000001;
		while (!(wall_finder(img, c, angle, j)))
			epic_raycasting(&c, structure->player_pos->xx, \
			structure->player_pos->yy, angle);
		wall_painter(img, j - 1, c, angle);
	}
	wall_painter(img, structure->win_w - 1, c, angle);
	sprite_finder(img, structure->player_pos->player_facing - M_PI_2 / 3);
	free(img->wall_d);
}
