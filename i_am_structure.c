/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 14:55:21 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/26 18:39:27 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		i_am_structure_init(t_map *structure)
{
	structure->win_w = 0;
	structure->win_h = 0;
	structure->no_path = NULL;
	structure->so_path = NULL;
	structure->we_path = NULL;
	structure->ea_path = NULL;
	structure->sprite_path = NULL;
	structure->f_r = -1;
	structure->f_g = -1;
	structure->f_b = -1;
	structure->c_r = -1;
	structure->c_g = -1;
	structure->c_b = -1;
	if (!(structure->player_pos = malloc(sizeof(t_player))))
		structure->error = 1;
	structure->player_pos->x = -1;
	structure->player_pos->y = -1;
	structure->map_in_line = NULL;
	structure->map_start = 0;
	structure->sprite_path = 0;
	structure->sprite_num = 0;
	structure->save = 0;
}
