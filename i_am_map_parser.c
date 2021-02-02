/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_map_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 18:58:42 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/28 16:57:35 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		double_free(char *s1, char *s2)
{
	free(s1);
	free(s2);
	s1 = NULL;
	s2 = NULL;
}

static int		check_new_line(char *line)
{
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (0);
	}
	return (1);
}

char			*i_am_map_parser(char *line, int fd)
{
	char	*map;
	char	*tmp;

	if (!line)
		return (NULL);
	map = ft_strdup(line, -1);
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		if (!(check_new_line(line)))
			return (map);
		tmp = map;
		map = ft_strjoin(map, "\n");
		free(tmp);
		tmp = map;
		map = ft_strjoin(map, line);
		double_free(tmp, line);
	}
	tmp = map;
	map = ft_strjoin(map, "\n");
	free(tmp);
	tmp = map;
	map = ft_strjoin(map, line);
	double_free(tmp, line);
	return (map);
}

int				check_map_again(int fd, char *line)
{
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) != 0)
		{
			ft_putstr_fd("map is not valid !\n", 1);
			free(line);
			return (0);
		}
		else
			free(line);
	}
	if (ft_strlen(line) != 0)
	{
		ft_putstr_fd("map is not valid !\n", 1);
		free(line);
		return (0);
	}
	else
		free(line);
	return (1);
}
