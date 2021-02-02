/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_sprite_engine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 20:36:52 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/28 23:11:08 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		another_one_wall_finder(t_data *img, \
double c, double angle)
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
		return (1);
	return (0);
}

static int		sprite_finded(t_data *img)
{
	int		i;

	i = 0;
	while (i < img->structure->sprite_num)
	{
		if ((int)img->structure->player_pos->xx + 0.5 == img->sprites[i].x && \
		(int)img->structure->player_pos->yy + 0.5 == img->sprites[i].y)
			return (1);
		i++;
	}
	return (0);
}

static void		set_sprite(t_data *img)
{
	int		i;

	i = 0;
	while (img->sprites[i].x != 0 && img->sprites[i].y != 0)
		i++;
	img->sprites[i].x = (int)img->structure->player_pos->xx + 0.5;
	img->sprites[i].y = (int)img->structure->player_pos->yy + 0.5;
	img->sprites[i].c = sqrt(pow(img->structure->player_pos->x - \
	img->sprites[i].x, 2) + pow(img->structure->player_pos->y - \
	img->sprites[i].y, 2));
	img->sprites[i].angle = \
	correctangle2(atan2((img->sprites[i].y - img->structure->player_pos->y),\
		(img->sprites[i].x - img->structure->player_pos->x)), \
		img->structure->player_pos->player_facing);
}

void			dodge_norminette(t_data *img, int *i)
{
	if (img->structure->map[(int)(img->structure->player_pos->yy)]\
	[(int)(img->structure->player_pos->xx)] == '2' && \
	sprite_finded(img) == 0)
	{
		set_sprite(img);
		*i += 1;
	}
}

void			sprite_finder(t_data *img, double angle)
{
	int			j;
	double		c;
	int			i;

	clear_sprites(img);
	j = 0;
	i = 0;
	while (j < img->structure->win_w)
	{
		angle = correctangle(angle + ((M_PI / 3) / img->structure->win_w) * 5);
		c = 0.000001;
		while (!(another_one_wall_finder(img, c, angle)))
		{
			epic_raycasting(&c, img->structure->player_pos->xx, \
			img->structure->player_pos->yy, angle);
			dodge_norminette(img, &i);
		}
		j += 5;
	}
	sprite_painter(img, i);
}
