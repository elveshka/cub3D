/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:51:52 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/27 22:08:18 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_resolution(t_map *structure, char *line)
{
	if (*line != ' ')
		return (0);
	while (*line == ' ' && *line)
		line++;
	while (*line != ' ' && *line)
	{
		if (ft_isdigit(*line))
			(structure)->win_w = (structure)->win_w * 10 + (*line - 48);
		else
			return (0);
		line++;
	}
	while (*line == ' ' && *line)
		line++;
	while (*line != ' ' && *line)
	{
		if (ft_isdigit(*line))
			(structure)->win_h = (structure)->win_h * 10 + (*line - 48);
		else
			return (0);
		line++;
	}
	while (*line == ' ' && *line)
		line++;
	return (*line != '\0' ? 0 : 1);
}

static int	parse_textures(char **path, char *line)
{
	if (*path)
		return (0);
	line += 2;
	if (*line != ' ')
		return (0);
	while (*line == ' ' && *line)
		line++;
	*path = ft_strdup(line, -1);
	return (1);
}

static int	if_textures(t_map *structure, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (parse_textures(&structure->no_path, line) ? 1 : 0);
	else if (ft_strncmp(line, "EA", 2) == 0)
		return (parse_textures(&structure->ea_path, line) ? 1 : 0);
	else if (ft_strncmp(line, "SO", 2) == 0)
		return (parse_textures(&structure->so_path, line) ? 1 : 0);
	else if (ft_strncmp(line, "WE", 2) == 0)
		return (parse_textures(&structure->we_path, line) ? 1 : 0);
	else if (ft_strncmp(line, "S", 1) == 0)
	{
		if (structure->sprite_path)
			return (0);
		line++;
		if (*line != ' ')
			return (0);
		(structure)->sprite_path = ft_strtrim(line, " ");
	}
	return (1);
}

int			parse_game_settings(t_map *structure, char *line)
{
	if (!(*line))
		return (1);
	else if (ft_strncmp(line, "R", 1) == 0)
	{
		if (structure->win_h != 0 && structure->win_w != 0)
			return (0);
		line++;
		if (!(parse_resolution(structure, line)))
			return (0);
	}
	else if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0 \
	|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0 || \
	ft_strncmp(line, "S", 1) == 0)
		return ((if_textures(structure, line)) ? 1 : 0);
	else if (ft_strncmp(line, "F", 1) == 0)
		return ((parse_floor(structure, line)) ? 1 : 0);
	else if (ft_strncmp(line, "C", 1) == 0)
		return ((parse_ceil(structure, line)) ? 1 : 0);
	else
		structure->map_start = 1;
	return (1);
}
