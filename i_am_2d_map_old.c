/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 15:49:14 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/20 00:10:30 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void			pixel_put_line(t_data *img, int j, double c, double angle)
{
	int x;
	double pixel_max;
	int end;
	int i = 1;

	pixel_max = img->structure->win_h / (c * cos(img->structure->player_pos->player_facing - angle));
	end = img->structure->win_h / 2 + pixel_max / 2;
	if (end > img->structure->win_h)
		end = img->structure->win_h - 10;
	x = img->structure->win_h / 2 - pixel_max / 2;
	if (x <= 0)
		x = 1;
	while (i < img->structure->win_h - 10)
	{
		if (i >= x && i <= end)
			pixel_put(img, j, i, 0xFFFFFF);
		else if (i < x)
			pixel_put(img, j, i, 0xFF4764);
		else
			pixel_put(img, j, i, 0xFF3333);
		i++;
	}
}
static double  countres(double xx, double yy)
{
    if (fabs(xx) == 0)
        return (fabs(yy) + 0.001);
    else if (fabs(yy) == 0)
        return (fabs(xx) + 0.001);
    else if (fabs(xx) < fabs(yy))
        return (fabs(xx) + 0.001);
    else
        return (fabs(yy) + 0.001);
}

int         wallfounder(t_data *img, double c, double angle1)
{
	double cx,cy;
    img->structure->player_pos->xx = img->structure->player_pos->x + c * cos(angle1);
    img->structure->player_pos->yy = img->structure->player_pos->y + c * sin(angle1);
	// printf("%f, %f\n", img->structure->player_pos->x, img->structure->player_pos->y);
	// printf("%f, %f\n", cx, cy);
    if (img->structure->map[(int)img->structure->player_pos->yy][(int)img->structure->player_pos->xx] == '1' \
        || img->structure->map[(int)img->structure->player_pos->yy][(int)img->structure->player_pos->xx] == '\0')
        return (1);
    return (0);
}
static double  correctangle(double angle)
{
    if (angle >= 2 * M_PI)
        return (angle - 2 * M_PI);
    else if (angle < 0)
        return (angle + 2 * M_PI);
    return (angle);
}

static double    dostep1(double *c, double x, double y, double angle)
{
    double xx;
    double yy;
    double result;

	xx = (x - (int)x) / (cos(correctangle(angle)));
        yy = (y - (int)y) / (sin(correctangle(angle)));
    if ((angle > 0 && angle <= M_PI_2) ||\
    (angle > 0 + 2 * M_PI && angle <= M_PI_2 + 2 * M_PI))
	{
        xx = (x - (int)x) / (cos(correctangle(angle)));
        yy = (y - (int)y) / (sin(correctangle(angle)));
	}
    else if (angle > M_PI_2 && angle < M_PI)
        xx = (x - (int)x) / (cos(correctangle(angle)));
    else if (angle <= -M_PI_2 + 2 * M_PI && angle >= M_PI)
    {
            xx = ((int)x - x + 1) / cos(angle);
    yy = ((int)y - y + 1) / sin(angle);
    }
    else
        yy = (y - (int)y) / (sin(correctangle(angle)));
    result = countres(xx, yy);
    *c = *c + result;
	return (result);
}

static void			print_3d(t_map *structure, t_data *img)
{
	double	c;
	double	cx;
	double	cy;
	int		j;
	double	angle = structure->player_pos->player_facing - M_PI_2 / 3;
	double dostep;
	j = -1;
	while (++j <= structure->win_w)
	{
		angle = angle + (M_PI / 3) / structure->win_w;
		c = 0.000001;
		while (wallfounder(img, c, angle) == 0)
			dostep = dostep1(&c, structure->player_pos->xx, structure->player_pos->yy, angle);
		/* c -= dostep;
		while (c)
		{
			cx = img->structure->player_pos->x + c * cos(angle);
   			cy = img->structure->player_pos->y + c * sin(angle);
			if (structure->map[(int)cy][(int)cx] != '0')
				break;
			c += 0.001;
		} */
		pixel_put_line(img, j, c, angle);
	}
}

int					any_key(int keycode, t_data *img)
{
	if (keycode == 13 || keycode == 126)
	{
		img->structure->player_pos->y += 0.1 * sin(img->structure->player_pos->player_facing);
		img->structure->player_pos->x += 0.1 * cos(img->structure->player_pos->player_facing);
		//read_2d_map(img->structure, img);
		print_3d(img->structure, img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	}
	else if (keycode == 1 || keycode == 125)
	{
		img->structure->player_pos->y += 0.1 * sin(img->structure->player_pos->player_facing + M_PI);
		img->structure->player_pos->x += 0.1 * cos(img->structure->player_pos->player_facing + M_PI);
		//read_2d_map(img->structure, img);
		print_3d(img->structure, img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	}
	else if (keycode == 0)
	{
		img->structure->player_pos->y += 0.1 * sin(img->structure->player_pos->player_facing - M_PI_2);
		img->structure->player_pos->x += 0.1 * cos(img->structure->player_pos->player_facing - M_PI_2);
		//read_2d_map(img->structure, img);
		print_3d(img->structure, img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	}
	else if (keycode == 2)
	{
		img->structure->player_pos->y += 0.1 * sin(img->structure->player_pos->player_facing + M_PI_2);
		img->structure->player_pos->x += 0.1 * cos(img->structure->player_pos->player_facing + M_PI_2);
		//read_2d_map(img->structure, img);
		print_3d(img->structure, img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	}
	else if (keycode == 124)
	{
		img->structure->player_pos->player_facing += 0.1;
		//read_2d_map(img->structure, img);
		print_3d(img->structure, img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	}
	else if (keycode == 123)
	{
		img->structure->player_pos->player_facing -= 0.1;
		//read_2d_map(img->structure, img);
		print_3d(img->structure, img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	}
	else if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit(0);
	}
	else
		;
	return(0);
}

void				i_am_2d_map(t_map *structure)
{
	t_data		img;
	void		*mlx;
	void		*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, structure->win_w, structure->win_h, "cub2d");
	img.mlx = mlx;
	img.mlx_win = mlx_win;
	img.img = mlx_new_image(mlx, structure->win_w, structure->win_h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	printf("%d -line_length\n%d -endian\n%d -bbp\n", img.line_length, img.endian, img.bits_per_pixel);
	img.structure = structure;
	//read_2d_map(structure, &img);
	print_3d(structure, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx_win, 2, 1L<<0, any_key, &img);
	mlx_loop(mlx);
}
