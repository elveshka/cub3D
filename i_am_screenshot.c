/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_screenshot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 22:32:01 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/28 20:26:59 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		screen_shot(t_data *img, char **bmp)
{
	unsigned int	size;

	size = img->structure->win_w * img->structure->win_h;
	ft_bzero(*bmp, sizeof(int) * size + 54);
	ft_memcpy(*bmp, "BM", 2);
	size = sizeof(int) * img->structure->win_w * img->structure->win_h + 54;
	ft_memcpy(*bmp + 2, &size, 4);
	size = 54;
	ft_memcpy(*bmp + 10, &size, 4);
	size = 40;
	ft_memcpy(*bmp + 14, &size, 4);
	ft_memcpy(*bmp + 18, &img->structure->win_w, 4);
	size = -img->structure->win_h;
	ft_memcpy(*bmp + 22, &size, 4);
	size = 1;
	ft_memcpy(*bmp + 26, &size, 2);
	ft_memcpy(*bmp + 28, (short*)&img->bits_per_pixel, 2);
	size = img->structure->win_w * img->structure->win_h;
	ft_memcpy(*bmp + 34, &size, 4);
}

void		screenshot(t_data *img)
{
	char	*bmp;
	char	*scrn;
	int		fd;
	int		y;

	y = 0;
	bmp = (char *)malloc(sizeof(int) * \
	(img->structure->win_w * img->structure->win_h + 54));
	screen_shot(img, &bmp);
	scrn = bmp + 54;
	while (y < img->structure->win_h)
	{
		ft_memcpy(scrn, img->addr, img->structure->win_w * sizeof(int));
		img->addr += img->line_length;
		scrn += (img->structure->win_w * sizeof(int));
		y++;
	}
	fd = open("screenshot.bmp", O_WRONLY | O_TRUNC | O_CREAT, 0666);
	write(fd, bmp, sizeof(int) * \
	(img->structure->win_w * img->structure->win_h) + 54);
	close(fd);
	free(bmp);
	bmp = NULL;
	exit(0);
}
