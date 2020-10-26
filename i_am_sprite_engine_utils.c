/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_sprite_engine_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:28:57 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/24 21:11:27 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static int			get_collor(t_xpm *img, int x, int y)
{
	char	*dst;
	int		color;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	color = *(int*)dst;
	return (color);
}

int		get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

double		setcos(double mainangle, double angle)
{
	double cosin;

	cosin = cos(mainangle - angle);
	if (cosin < 0.85)
		cosin = 0.85;
	return (cosin);
}

void		putlinesprite(t_data *img, int i, int l, double pixelhiegt)
{
	int k;
	int collor;

	k = 0;
	while (k < img->structure->win_h)
	{
		collor = get_collor(img->sprite, img->sprite->w \
		* (l / pixelhiegt), img->sprite->h * \
		((pixelhiegt - img->structure->win_h) / 2 + k) / pixelhiegt);
		if (get_t(collor) == 0)
			my_mlx_pixel_put(img, i + l, k, collor);
		k++;
	}
}

void		putlinebigsprite(t_data *img, int i, int l, double pixelhiegt)
{
	int k;
	int collor;

	k = (img->structure->win_h - pixelhiegt) / 2 + 1;
	while (k < (img->structure->win_h - pixelhiegt) / 2 + pixelhiegt)
	{
		collor = get_collor(img->sprite, img->sprite->w \
		* (l / pixelhiegt), img->sprite->h \
		* (k - (img->structure->win_h - pixelhiegt) / 2) / pixelhiegt);
		if (get_t(collor) == 0)
			my_mlx_pixel_put(img, i + l, k, collor);
		k++;
	}
}

void		putsprite(t_data *img, int num)
{
	double		i;
	int			l;
	double		pixelhiegt;
	double		cosin;

	cosin = setcos(img->structure->player_pos->player_facing, \
	img->sprites[num].angle);
	pixelhiegt = 0.5 * img->structure->win_h / (img->sprites[num].c * cosin);
	i = (img->structure->win_w / 2 + \
	(img->sprites[num].angle - img->structure->player_pos->player_facing) \
	/ (M_PI / (img->structure->win_w * 3)) - pixelhiegt / 2);
	l = 0;
	while (l < pixelhiegt)
	{
		if (i + l > 0 && img->sprites[num].c < img->wall_d[(int)(\
		(img->structure->win_w - l - i))] && \
		i + l < img->structure->win_w)
		{
			if (pixelhiegt > img->structure->win_h)
				putlinesprite(img, i, l, pixelhiegt);
			else
				putlinebigsprite(img, i, l, pixelhiegt);
		}
		l++;
	}
}
