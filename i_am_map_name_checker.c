/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_map_name_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:49:36 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/28 22:44:58 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_map_name(char *str)
{
	int	i;
	int	fd;

	if ((i = ft_strlen(str)) < 4)
	{
		ft_putstr_fd("Wrong map name!\n", 1);
		return (-1);
	}
	if (str[i - 1] != 'b' || str[i - 2] != 'u' || str[i - 3] != 'c' || \
	str[i - 4] != '.')
	{
		ft_putstr_fd("Wrong map name!\n", 1);
		return (-1);
	}
	if ((fd = open(str, O_RDONLY)) < 0)
	{
		ft_putstr_fd("No file\n", 1);
		return (fd);
	}
	return (fd);
}
