/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_sprite_engine_utils2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:47:31 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/28 20:48:27 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		correctangle2(double angle, double player_facing)
{
	if (angle + M_PI_2 < player_facing)
		return (angle + 2 * M_PI);
	else if (angle - M_PI_2 > player_facing)
		return (angle - 2 * M_PI);
	return (angle);
}

void		clear_sprites(t_data *img)
{
	int		i;

	i = 0;
	while (i < img->structure->sprite_num)
	{
		img->sprites[i].angle = 0;
		img->sprites[i].y = 0;
		img->sprites[i].x = 0;
		img->sprites[i].c = 0;
		i++;
	}
}
