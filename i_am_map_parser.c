/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_map_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 18:58:42 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/22 18:43:13 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		if (ft_strlen(line) == 0)
			return(map);
		tmp = map;
		map = ft_strjoin(map, "\n");
		free(tmp);
		tmp = map;
		map = ft_strjoin(map, line);
		free(tmp);
		free(line);
	}
	tmp = map;
	map = ft_strjoin(map, "\n");
	free(tmp);
	tmp = map;
	map = ft_strjoin(map, line);
	free(tmp);
	free(line);
	return (map);
}
