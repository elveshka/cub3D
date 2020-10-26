/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_map_reader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:25:12 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/23 20:51:03 by esnowbal         ###   ########.fr       */
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

static int		line_count(char **map)
{
	int i;

	i = 0;
	while(map[i++])
		;
	return (i - 1);
}

static int		max_line(char **mapp)
{
	int		res;
	int		i;
	char	**map;
	char	*line;

	map = mapp;
	res = 0;
	while (*map)
	{
		i = 0;
		line = *map;
		while (*line)
		{
			i++;
			line++;
		}
		res = (i > res) ? i : res;
		map++;
	}
	return (res);
}

static void		space_fill(char **map, int max)
{
	char	**tmp_map;
	char	*line;
	int		i;

	tmp_map = map;
	while (*tmp_map)
	{
		if (ft_strlen(*tmp_map) < max)
		{
			line = *tmp_map;
			*tmp_map = malloc(sizeof(char) * max + 1);
			(*tmp_map)[max] = '\0';
			i = -1;
			while (line[++i])
				(*tmp_map)[i] = line[i];
			while (i < max)
			{
				(*tmp_map)[i] = ' ';
				i++;
			}
			free(line);
		}
		tmp_map++;
	}
}

static int		map_validating(t_map *structure)
{
	int		max_x;
	int		max_y;
	int		i;
	int		j;

	max_x = max_line(structure->map);
	max_y = line_count(structure->map);
	space_fill(structure->map, max_x);
	i = 0;
	while (i < max_x)
	{
		if ((structure->map[0][i] != '1' && structure->map[0][i] != ' ') \
		|| (structure->map[max_y - 1][i] != ' ' \
		&& structure->map[max_y - 1][i] != '1'))
			return (0);
		i++;
	}
	i = 0;
	while (i < max_y)
	{
		if ((structure->map[i][0] != '1' && structure->map[i][0] != ' ') \
		|| (structure->map[i][max_x - 1] != ' ' && \
		structure->map[i][max_x - 1] != '1'))
			return (0);
		i++;
	}
	j = 1;
	while (j < max_y)
	{
		i = 1;
		while(i < max_x)
		{
			if (structure->map[j][i] == '0' && \
			(structure->map[j - 1][i] == ' ' || \
			structure->map[j][i - 1] == ' ' || \
			structure->map[j + 1][i] == ' ' || \
			structure->map[j][i + 1] == '\0' || \
			structure->map[j][i + 1] == ' '))
				return (0);
			else if (structure->map[j][i] == '2' && \
			(structure->map[j - 1][i] == ' ' || \
			structure->map[j][i - 1] == ' ' || \
			structure->map[j + 1][i] == ' ' || \
			structure->map[j][i + 1] == '\0' || \
			structure->map[j][i + 1] == ' '))
				return (0);
			else if (structure->map[j][i] != '0' \
			&& structure->map[j][i] != '1' \
			&& structure->map[j][i] != '2' \
			&& structure->map[j][i] != ' ')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int			i_am_map_reader(t_map *structure, char *map_in_line)
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
