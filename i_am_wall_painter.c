/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_wall_painter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:39:39 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/28 20:04:14 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double		find_height(t_player *player, char name)
{
	if (name == 'e')
		return (player->yy - (int)player->yy);
	else if (name == 'w')
		return ((int)player->yy + 1 - player->yy);
	else if (name == 'n')
		return (player->xx - (int)player->xx);
	else
		return ((int)player->xx + 1 - player->xx);
}

static double		find_weight(double wall_h, int h, int i)
{
	if (wall_h > h)
		return ((wall_h / 2 - h / 2 + i) / wall_h);
	else
		return ((i - (h / 2 - wall_h / 2)) / wall_h);
}

static t_xpm		*what_wall(t_data *img)
{
	if ((int)(img->structure->player_pos->xx - 0.00001) != \
	(int)(img->structure->player_pos->xx))
		return (img->ea_img);
	else if ((int)(img->structure->player_pos->xx + 0.00001) != \
	(int)(img->structure->player_pos->xx))
		return (img->we_img);
	else if ((int)(img->structure->player_pos->yy - 0.00001) != \
	(int)(img->structure->player_pos->yy))
		return (img->so_img);
	else
		return (img->no_img);
}

static void			wall_painter_2(t_data *img, double wall_height, int j)
{
	int		i;
	t_xpm	*current_wall;
	int		pixel;
	int		end;

	i = 0;
	end = img->structure->win_h / 2 + wall_height / 2;
	end = (end > img->structure->win_h) ? img->structure->win_h : end;
	pixel = img->structure->win_h / 2 - wall_height / 2;
	current_wall = what_wall(img);
	while (i < img->structure->win_h)
	{
		if (i > pixel && i <= end)
			pixel_put(img, j, i, get_color(current_wall, \
			find_height(img->structure->player_pos, current_wall->name) * \
			current_wall->w, current_wall->h * find_weight(wall_height, \
			img->structure->win_h, i)));
		else if (i <= pixel)
			pixel_put(img, j, i, create_trgb(0, img->structure->c_r, \
			img->structure->c_g, img->structure->c_b));
		else
			pixel_put(img, j, i, create_trgb(0, img->structure->f_r, \
			img->structure->f_g, img->structure->f_b));
		i++;
	}
}

void				wall_painter(t_data *img, int j, double c, double angle)
{
	double	wall_height;

	wall_height = img->structure->win_h / \
	(c * cos(img->structure->player_pos->player_facing - angle));
	wall_painter_2(img, wall_height, j);
}
