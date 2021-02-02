/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_res_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:01:01 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/28 21:02:18 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_resolution(t_data *img)
{
	int	sizex;
	int	sizey;

	sizex = 0;
	sizey = 0;
	mlx_get_screen_size(img->mlx, &sizex, &sizey);
	if (img->structure->win_w > sizex)
		img->structure->win_w = sizex;
	if (img->structure->win_h > sizey)
		img->structure->win_h = sizey;
}
