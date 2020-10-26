/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_sprite_engine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 20:36:52 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/24 22:32:48 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	another_one_wall_finder (t_data *img, double c, double angle, int j)
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

static double	correctangle2(double angle, double player_facing)
{
	if (angle + M_PI_2 < player_facing)
		return (angle + 2 * M_PI);
	else if (angle - M_PI_2 > player_facing)
		return (angle - 2 * M_PI);
	return (angle);
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

static t_sprite	*sort(t_sprite *sprites, int num)
{
	int			i;
	int			f;
	t_sprite	tmp;

	f = 1;
	while (f > 0)
	{
		f = 0;
		i = -1;
		while (++i < num - 1)
		{
			if (sprites[i].c < sprites[i + 1].c)
			{
				tmp = sprites[i + 1];
				sprites[i + 1] = sprites[i];
				sprites[i] = tmp;
				f++;
			}
		}
	}
	return (sprites);
}

static void	sprite_painter(t_data *img, int num)
{
	int		c;

	img->sprites = sort(img->sprites, num);
	c = 0;
	while (c < num)
	{
		if (img->sprites[c].c > 0.7)
			putsprite(img, c);
		c++;
	}
}

void		sprite_finder(t_data *img, double angle)
{
	int			j;
	double		c;
	int			i;

	i = 0;
	j = 0;
	while (i < img->structure->sprite_num)
	{
		img->sprites[i].angle = 0;
		img->sprites[i].y = 0;
		img->sprites[i].x = 0;
		img->sprites[i].c = 0;
		i++;
	}
	i = 0;
	while (j < img->structure->win_w)
	{
		angle = angle + ((M_PI / 3) / img->structure->win_w) * 5;
		angle =correctangle(angle);
		c = 0.000001;
		while (!(another_one_wall_finder(img, c, angle, j)))
		{
			epic_raycasting(&c, img->structure->player_pos->xx, \
			img->structure->player_pos->yy, angle);
			if (img->structure->map[(int)(img->structure->player_pos->yy)]\
			[(int)(img->structure->player_pos->xx)] == '2' && \
			sprite_finded(img) == 0)
			{
				set_sprite(img);
				i++;
			}
		}
		j += 5;
	}
	sprite_painter(img, i);
}
