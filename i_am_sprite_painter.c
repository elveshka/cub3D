/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_sprite_painter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:28:37 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/28 20:29:50 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_sprite		*sort(t_sprite *sprites, int num)
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

void				sprite_painter(t_data *img, int num)
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
