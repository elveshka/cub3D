/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_map_reader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:25:12 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/28 17:08:40 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		set_player_facing(t_map *structure, char c)
{
	if (c == 'N')
		structure->player_pos->player_facing = M_PI_2 * 3;
	if (c == 'E')
		structure->player_pos->player_facing = 0;
	if (c == 'S')
		structure->player_pos->player_facing = M_PI_2;
	if (c == 'W')
		structure->player_pos->player_facing = M_PI;
}

static int		is_player_pos(t_map *structure, char **tmp, int *x, int *y)
{
	while (**tmp)
	{
		if (**tmp == 'N' || **tmp == 'E' || \
		**tmp == 'W' || **tmp == 'S')
		{
			if (structure->player_pos->x != -1)
				return (0);
			set_player_facing(structure, **tmp);
			structure->player_pos->x = (double)(*x) + 0.5;
			structure->player_pos->y = (double)(*y) + 0.5;
			**tmp = '0';
		}
		if (**tmp == '2')
			structure->sprite_num++;
		(*x)++;
		(*tmp)++;
	}
	return (1);
}

int				map_check(t_map *structure, int i, int j, int flag)
{
	if (flag == 0)
	{
		if (structure->map[j][i] == '0' && (structure->map[j - 1][i] == ' ' || \
			structure->map[j][i - 1] == ' ' || \
			structure->map[j + 1][i] == ' ' || \
			structure->map[j][i + 1] == '\0' || \
			structure->map[j][i + 1] == ' '))
			return (0);
	}
	else if (flag == 1)
	{
		if (structure->map[j][i] == '2' && (structure->map[j - 1][i] == ' ' || \
			structure->map[j][i - 1] == ' ' || \
			structure->map[j + 1][i] == ' ' || \
			structure->map[j][i + 1] == '\0' || \
			structure->map[j][i + 1] == ' '))
			return (0);
	}
	else
	{
		if (structure->map[j][i] != '0' && structure->map[j][i] != '1' \
			&& structure->map[j][i] != '2' && structure->map[j][i] != ' ')
			return (0);
	}
	return (1);
}

int				i_am_map_reader(t_map *structure, char *map_in_line)
{
	int		x;
	int		y;
	int		i;
	char	*tmp;

	i = 0;
	x = 0;
	y = 0;
	structure->map = ft_split(map_in_line, '\n');
	while (structure->map[i])
	{
		tmp = structure->map[i];
		if (!(is_player_pos(structure, &tmp, &x, &y)))
			return (0);
		y++;
		i++;
		x = 0;
	}
	if (!(map_validating(structure)))
		return (0);
	return (1);
}
