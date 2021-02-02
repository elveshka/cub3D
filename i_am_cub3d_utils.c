/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_cub3d_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:36:00 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/28 17:53:53 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_all(t_data *img, void **mlx, void **mlx_win)
{
	no_img_init(*mlx, img);
	we_img_init(*mlx, img);
	so_img_init(*mlx, img);
	ea_img_init(*mlx, img);
	s_img_init(*mlx, img);
	if (img->structure->error == 1)
	{
		ft_putstr_fd("Invalid textures !\n", 1);
		exit(1);
	}
	*mlx_win = mlx_new_window(*mlx, \
	img->structure->win_w, img->structure->win_h, "cub3D");
	img->mlx = *mlx;
	img->mlx_win = *mlx_win;
	img->img = mlx_new_image(*mlx, img->structure->win_w, \
	img->structure->win_h);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
}
