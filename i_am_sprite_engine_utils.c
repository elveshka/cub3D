/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_sprite_engine_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:28:57 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/28 22:03:34 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				get_t(int color)
{
	return (color & (0xFF << 24));
}

double			setcos(double mainangle, double angle)
{
	double cosin;

	cosin = cos(mainangle - angle);
	if (cosin < 0.85)
		cosin = 0.85;
	return (cosin);
}

static void		put_line_sprite(t_data *img, int i, int l, double pixelheight)
{
	int k;
	int color;

	k = (img->structure->win_h - pixelheight) / 2 + 1;
	while (k < (img->structure->win_h - pixelheight) / 2 + pixelheight)
	{
		color = get_color(img->sprite, img->sprite->w \
		* (l / pixelheight), img->sprite->h \
		* (k - (img->structure->win_h - pixelheight) / 2) / pixelheight);
		if (get_t(color) == 0)
			pixel_put(img, i + l, k, color);
		k++;
	}
}

void			putsprite(t_data *img, int num)
{
	double		i;
	int			l;
	double		pixelheight;
	double		cosin;

	cosin = setcos(img->structure->player_pos->player_facing, \
	img->sprites[num].angle);
	pixelheight = 0.4 * img->structure->win_h / (img->sprites[num].c * cosin);
	i = (img->structure->win_w / 2 + \
	(img->sprites[num].angle - img->structure->player_pos->player_facing) \
	/ (M_PI / (img->structure->win_w * 3)) - pixelheight / 2);
	l = 0;
	while (l < pixelheight)
	{
		if (i + l > 0 && img->sprites[num].c < img->wall_d[(int)(\
		(img->structure->win_w - l - i))] && \
		i + l < img->structure->win_w)
			put_line_sprite(img, i, l, pixelheight);
		l++;
	}
}
