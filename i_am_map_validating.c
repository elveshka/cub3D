/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_map_validating.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:59:37 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/28 17:12:25 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static int		line_count(char **map)
{
	int i;

	i = 0;
	while (map[i++])
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

static int		max_x_y(t_map *structure, int max_x, int max_y)
{
	int j;
	int i;

	j = 1;
	while (j < max_y)
	{
		i = 1;
		while (i < max_x)
		{
			if (!(map_check(structure, i, j, 0)))
				return (0);
			else if (!(map_check(structure, i, j, 1)))
				return (0);
			else if (!(map_check(structure, i, j, 2)))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int				map_validating(t_map *structure)
{
	int		max_x;
	int		max_y;
	int		i;

	i = -1;
	max_x = max_line(structure->map);
	max_y = line_count(structure->map);
	space_fill(structure->map, max_x);
	while (++i < max_x)
	{
		if ((structure->map[0][i] != '1' && structure->map[0][i] != ' ') \
		|| (structure->map[max_y - 1][i] != ' ' \
		&& structure->map[max_y - 1][i] != '1'))
			return (0);
	}
	i = -1;
	while (++i < max_y)
	{
		if ((structure->map[i][0] != '1' && structure->map[i][0] != ' ') \
		|| (structure->map[i][max_x - 1] != ' ' && \
		structure->map[i][max_x - 1] != '1'))
			return (0);
	}
	return (!(max_x_y(structure, max_x, max_y)) ? 0 : 1);
}
