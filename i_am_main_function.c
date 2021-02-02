/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_main_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:36:39 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/28 22:44:54 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		game_settings_check(t_map *structure)
{
	if (structure->win_h != 0 && structure->win_w != 0 \
	&& structure->no_path && \
	structure->so_path && structure->we_path && structure->ea_path && \
	structure->sprite_path && structure->f_r != -1 && \
	structure->c_r != -1 && structure->map_start)
		return (1);
	ft_putstr_fd("wrong game settings !\n", 1);
	return (0);
}

static int		check_args(t_map *structure, int argc, char **argv)
{
	if (argc < 2 || argc > 3)
	{
		ft_putstr_fd("wrong arguments !\n", 1);
		return (0);
	}
	else if (argc == 3 && !(ft_strcmp(argv[2], "--save")))
		structure->save = 1;
	else if (argc == 3 && ft_strcmp(argv[2], "--save"))
	{
		ft_putstr_fd("wrong arguments !\n", 1);
		return (0);
	}
	return (1);
}

static int		check_sprites(int sprites)
{
	if (sprites > 1000)
	{
		ft_putstr_fd("The number of sprites is more than 1000, leads to ", 1);
		ft_putstr_fd("a decrease in performance. :(\nDo not do that!\n", 1);
		return (0);
	}
	return (1);
}

int				main_2(t_map *structure, char *line, int fd)
{
	if (!(game_settings_check(structure)))
		return (0);
	if (!(structure->map_in_line = i_am_map_parser(line, fd)))
	{
		ft_putstr_fd("wrong game settings !\n", 1);
		return (0);
	}
	if (!(check_map_again(fd, line)))
	{
		free(structure->map_in_line);
		return (0);
	}
	line = NULL;
	if (!(i_am_map_reader(structure, structure->map_in_line)))
	{
		ft_putstr_fd("map is not valid !\n", 1);
		return (0);
	}
	free(structure->map_in_line);
	close(fd);
	if (!(check_sprites(structure->sprite_num)))
		return (0);
	i_am_cub3d(structure);
	return (1);
}

int				main(int argc, char **argv)
{
	t_map	structure;
	int		fd;
	char	*line;

	if ((fd = check_map_name(argv[1])) < 0)
		return (0);
	i_am_structure_init(&structure);
	if (!(check_args(&structure, argc, argv)))
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		if (!(parse_game_settings(&structure, line)))
		{
			ft_putstr_fd("wrong game settings !\n", 1);
			return (0);
		}
		if (structure.map_start)
			break ;
		free(line);
	}
	main_2(&structure, line, fd);
	return (0);
}
