/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_like_to_move_it.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:07:02 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/28 18:49:43 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			step_forward(t_data *img)
{
	if (img->structure->map[(int)(img->structure->player_pos->y + 0.2 * \
		sin(img->structure->player_pos->player_facing))]\
		[(int)(img->structure->player_pos->x + 0.2 * \
		cos(img->structure->player_pos->player_facing))] == '1' || \
		img->structure->map[(int)(img->structure->player_pos->y + 0.2 * \
		sin(img->structure->player_pos->player_facing))]\
		[(int)(img->structure->player_pos->x + 0.2 * \
		cos(img->structure->player_pos->player_facing))] == ' ' || \
		img->structure->map[(int)(img->structure->player_pos->y + 0.2 * \
		sin(img->structure->player_pos->player_facing))]\
		[(int)(img->structure->player_pos->x + 0.2 * \
		cos(img->structure->player_pos->player_facing))] == '\0')
		return (0);
	img->structure->player_pos->y += 0.2 * \
		sin(img->structure->player_pos->player_facing);
	img->structure->player_pos->x += 0.2 * \
		cos(img->structure->player_pos->player_facing);
	return (1);
}

int			step_backward(t_data *img)
{
	if (img->structure->map[(int)(img->structure->player_pos->y + 0.1 * \
		sin(img->structure->player_pos->player_facing + M_PI))]\
		[(int)(img->structure->player_pos->x + 0.1 * \
		cos(img->structure->player_pos->player_facing + M_PI))] == '1' || \
		img->structure->map[(int)(img->structure->player_pos->y + 0.1 * \
		sin(img->structure->player_pos->player_facing + M_PI))]\
		[(int)(img->structure->player_pos->x + 0.1 * \
		cos(img->structure->player_pos->player_facing + M_PI))] == ' ' || \
		img->structure->map[(int)(img->structure->player_pos->y + 0.1 * \
		sin(img->structure->player_pos->player_facing + M_PI))]\
		[(int)(img->structure->player_pos->x + 0.1 * \
		cos(img->structure->player_pos->player_facing + M_PI))] == '\0')
		return (0);
	img->structure->player_pos->y += 0.1 * \
		sin(img->structure->player_pos->player_facing + M_PI);
	img->structure->player_pos->x += 0.1 * \
		cos(img->structure->player_pos->player_facing + M_PI);
	return (1);
}

int			step_left(t_data *img)
{
	double x;
	double y;

	y = img->structure->player_pos->y + 0.1 * \
		sin(img->structure->player_pos->player_facing - M_PI_2);
	x = img->structure->player_pos->x + 0.1 * \
		cos(img->structure->player_pos->player_facing - M_PI_2);
	if ((img->structure->map[(int)y][(int)x] == '1' || \
		img->structure->map[(int)y][(int)x] == '\0' || \
		img->structure->map[(int)y][(int)x] == ' '))
		return (0);
	y = img->structure->player_pos->y + 0.2 * \
		sin(img->structure->player_pos->player_facing - M_PI_2);
	x = img->structure->player_pos->x + 0.2 * \
		cos(img->structure->player_pos->player_facing - M_PI_2);
	if ((img->structure->map[(int)y][(int)x] == '1' || \
		img->structure->map[(int)y][(int)x] == '\0' || \
		img->structure->map[(int)y][(int)x] == ' '))
		return (0);
	img->structure->player_pos->y += 0.1 * \
		sin(img->structure->player_pos->player_facing - M_PI_2);
	img->structure->player_pos->x += 0.1 * \
		cos(img->structure->player_pos->player_facing - M_PI_2);
	return (1);
}

int			step_right(t_data *img)
{
	double	y;
	double	x;

	y = img->structure->player_pos->y + 0.1 * \
		sin(img->structure->player_pos->player_facing + M_PI_2);
	x = img->structure->player_pos->x + 0.1 * \
		cos(img->structure->player_pos->player_facing + M_PI_2);
	if (img->structure->map[(int)y][(int)x] == '1' || \
		img->structure->map[(int)y][(int)x] == '\0' || \
		img->structure->map[(int)y][(int)x] == ' ')
		return (0);
	y = img->structure->player_pos->y + 0.2 * \
		sin(img->structure->player_pos->player_facing + M_PI_2);
	x = img->structure->player_pos->x + 0.2 * \
		cos(img->structure->player_pos->player_facing + M_PI_2);
	if (img->structure->map[(int)y][(int)x] == '1' || \
		img->structure->map[(int)y][(int)x] == '\0' || \
		img->structure->map[(int)y][(int)x] == ' ')
		return (0);
	img->structure->player_pos->y += 0.1 * \
		sin(img->structure->player_pos->player_facing + M_PI_2);
	img->structure->player_pos->x += 0.1 * \
		cos(img->structure->player_pos->player_facing + M_PI_2);
	return (1);
}
