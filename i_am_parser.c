/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:36:39 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/26 22:32:46 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		game_settings_check(t_map *structure)
{
	if (structure->win_h != 0 && structure->win_w != 0 \
	&& structure->no_path && \
	structure->so_path && structure->we_path && structure->ea_path && \
	structure->sprite_path && structure->f_r != -1 && \
	structure->c_r != -1)
		return (1);
	return (0);
}

static int		ft_is_str_all_digit (char *str)
{
	int res;

	res = 1;
	while (*str)
	{
		if (!(ft_isdigit(*str)))
		{
			res = 0;
			break;
		}
		str++;
	}
	return (res);
}

static int		parse_game_settings(t_map *structure, char *line)
{
	int comma;
	char	**split_line;

	if (!(*line))
		return (1);
	else if (ft_strncmp(line, "R", 1) == 0)
	{
		if (structure->win_h != 0 && structure->win_w != 0)
			return (0);
		line++;
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
		if (*line)
			return (0);
	}
	else if (ft_strncmp(line, "NO", 2) == 0)
	{
		if (structure->no_path)
			return (0);
		line += 2;
		if (*line != ' ')
			return (0);
		(structure)->no_path = ft_strtrim(line, " ");
	}
	else if (ft_strncmp(line, "EA", 2) == 0)
	{
		if (structure->ea_path)
			return (0);
		line += 2;
		if (*line != ' ')
			return (0);
		(structure)->ea_path = ft_strtrim(line, " ");
	}
	else if (ft_strncmp(line, "SO", 2) == 0)
	{
		if (structure->so_path)
			return (0);
		line += 2;
		if (*line != ' ')
			return (0);
		(structure)->so_path = ft_strtrim(line, " ");
	}
	else if (ft_strncmp(line, "WE", 2) == 0)
	{
		if (structure->we_path)
			return (0);
		line += 2;
		if (*line != ' ')
			return (0);
		(structure)->we_path = ft_strtrim(line, " ");
	}
	else if (ft_strncmp(line, "S", 1) == 0)
	{
		if (structure->sprite_path)
			return (0);
		line++;
		if (*line != ' ')
			return (0);
		(structure)->sprite_path = ft_strtrim(line, " ");
	}
	else if (ft_strncmp(line, "F", 1) == 0)
	{
		if (structure->f_r != -1 || structure->f_g != -1 || \
		structure->f_b != -1)
			return (0);
		line++;
		if (*line != ' ')
			return (0);
		while (*line == ' ')
			line++;
		if (!(*line) || !(ft_isdigit(*line)))
				return (0);
		structure->f_r = 0;
		while (ft_isdigit(*line))
		{
			structure->f_r = structure->f_r * 10 + *line - 48;
			line++;
			if (structure->f_r > 255)
				return (0);
		}
		comma = 0;
		while (*line == ' ' || *line == ',')
		{
			if (*line == ',')
				comma++;
			line++;
		}
		if (comma != 1 || !(ft_isdigit(*line)) || !(*line))
			return (0);
		structure->f_g = 0;
		while (ft_isdigit(*line))
		{
			structure->f_g = structure->f_g * 10 + *line - 48;
			line++;
			if (structure->f_g > 255)
				return (0);
		}
		comma = 0;
		while (*line == ' ' || *line == ',')
		{
			if (*line == ',')
				comma++;
			line++;
		}
		if (comma != 1 || !(ft_isdigit(*line)) || !(*line))
			return (0);
		structure->f_b = 0;
		while (ft_isdigit(*line))
		{
			structure->f_b = structure->f_b * 10 + *line - 48;
			line++;
			if (structure->f_b > 255)
				return (0);
		}
		while (*line)
		{
			if (*line != ' ')
				return (0);
			line++;
		}
	}
	else if (ft_strncmp(line, "C", 1) == 0)
	{
		if (structure->c_r != -1 || structure->c_g != -1 || \
		structure->c_b != -1)
			return (0);
		line++;
		if (*line != ' ')
			return (0);
		while (*line == ' ')
			line++;
		if (!(*line) || !(ft_isdigit(*line)))
				return (0);
		structure->c_r = 0;
		while (ft_isdigit(*line))
		{
			structure->c_r = structure->c_r * 10 + *line - 48;
			line++;
			if (structure->c_r > 255)
				return (0);
		}
		comma = 0;
		while (*line == ' ' || *line == ',')
		{
			if (*line == ',')
				comma++;
			line++;
		}
		if (comma != 1 || !(ft_isdigit(*line)) || !(*line))
			return (0);
		structure->c_g = 0;
		while (ft_isdigit(*line))
		{
			structure->c_g = structure->c_g * 10 + *line - 48;
			line++;
			if (structure->c_g > 255)
				return (0);
		}
		comma = 0;
		while (*line == ' ' || *line == ',')
		{
			if (*line == ',')
				comma++;
			line++;
		}
		if (comma != 1 || !(ft_isdigit(*line)) || !(*line))
			return (0);
		structure->c_b = 0;
		while (ft_isdigit(*line))
		{
			structure->c_b = structure->c_b * 10 + *line - 48;
			line++;
			if (structure->c_b > 255)
				return (0);
		}
		while (*line)
		{
			if (*line != ' ')
				return (0);
			line++;
		}
	}
	else
		structure->map_start = 1;
	return (1);
}

int				main(int argc, char **argv)
{
	t_map	structure;
	int		fd;
	char	*line;

	i_am_structure_init(&structure);
	if (argc < 2 || argc > 3)
		return (0);
	else if (argc == 3 && !(ft_strcmp(argv[2], "--save")))
		structure.save = 1;
	else if (argc == 3 && ft_strcmp(argv[2], "--save"))
	{
		ft_putstr_fd("wrong arguments !\n", 1);
		return (0);
	}
	if (structure.error == 1)
	{
		ft_putstr_fd("something wrong with malloc\n", 1);
		return(0);
	}
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (!(parse_game_settings(&structure, line)))
		{
			ft_putstr_fd("wrong game settings !\n", 1);
			return(0);
		}
		if (structure.map_start)
			break ;
		free(line);
	}
	if (game_settings_check(&structure) == 0)
	{
		ft_putstr_fd("wrong game settings !\n", 1);
		return(0);
	}
	if (!(structure.map_in_line = i_am_map_parser(line, fd)))
	{
		ft_putstr_fd("wrong game settings !\n", 1);
		return (0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) != 0)
		{
			ft_putstr_fd("map is not valid !\n", 1);
			free(line);
			return(0);
		}
		else
			free(line);
	}
	if (ft_strlen(line) != 0)
	{
		ft_putstr_fd("map is not valid !\n", 1);
		free(line);
		return(0);
	}
	free(line);
	line = NULL;
	if (!(i_am_map_reader(&structure, structure.map_in_line)))
	{
		ft_putstr_fd("map is not valid !\n", 1);
		return(0);
	}
	free(structure.map_in_line);
	close(fd);
	if (structure.sprite_num > 1000)
	{
		ft_putstr_fd("The number of sprites is more than 1000, leads to ", 1);
		ft_putstr_fd("a decrease in performance. :(\nDo not do that!\n", 1);
		return (0);
	}
	i_am_cub3d(&structure);
	return (0);
}
