/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_cub3D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 15:49:14 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/26 22:42:50 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static int			get_color(t_xpm *img, int x, int y)
{
	char	*dst;
	int		color;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	color = *(int*)dst;
	return (color);
}

static t_xpm		*what_wall(t_data *img)
{
	if ((int)(img->structure->player_pos->xx - 0.00001) != \
	(int)(img->structure->player_pos->xx))
		return(img->ea_img);
	else if ((int)(img->structure->player_pos->xx + 0.00001) != \
	(int)(img->structure->player_pos->xx))
		return(img->we_img);
	else if ((int)(img->structure->player_pos->yy - 0.00001) != \
	(int)(img->structure->player_pos->yy))
		return (img->so_img);
	else
		return (img->no_img);
}
static double		find_height(t_player *player, char name)
{
	if (name == 'e')
		return (player->yy - (int)player->yy);
	else if (name == 'w')
		return ((int)player->yy + 1 - player->yy);
	else if (name == 'n')
		return (player->xx - (int)player->xx);
	else
		return ((int)player->xx + 1 - player->xx);
}
static double		find_weight(double wall_h, int h, int i)
{
	if (wall_h > h)
		return ((wall_h / 2 - h / 2 + i) / wall_h);
	else
		return ((i - (h / 2 - wall_h / 2)) / wall_h);
}

static void			wall_painter(t_data *img, int j, double c, double angle)
{
	int		pixel;
	double	wall_height;
	int		end;
	int		i;
	t_xpm	*current_wall;
	double	find_y;
	int		find_x;

	i = 0;
	wall_height = img->structure->win_h / \
	(c * cos(img->structure->player_pos->player_facing - angle));
	end = img->structure->win_h / 2 + wall_height / 2;
	if (end > img->structure->win_h)
		end = img->structure->win_h;
	pixel = img->structure->win_h / 2 - wall_height / 2;
	current_wall = what_wall(img);
	find_y = find_height(img->structure->player_pos, current_wall->name);
	while (i < img->structure->win_h)
	{
		if (i > pixel && i <= end)
			pixel_put(img, j, i, get_color(current_wall, find_y * \
			current_wall->w, current_wall->h * find_weight(wall_height, \
			img->structure->win_h, i)));
		else if (i <= pixel)
			pixel_put(img, j, i, create_trgb(0, img->structure->c_r, \
			img->structure->c_g, \
			img->structure->c_b));
		else
			pixel_put(img, j, i, create_trgb(0, img->structure->f_r, \
			img->structure->f_g, \
			img->structure->f_b));
		i++;
	}
}

static double		countres(double xx, double yy)
{
	if (fabs(xx) == 0)
		return (fabs(yy) + 0.000001);
	else if (fabs(yy) == 0)
		return (fabs(xx) + 0.000001);
	else if (fabs(xx) < fabs(yy))
		return (fabs(xx) + 0.000001);
	else
		return (fabs(yy) + 0.000001);
}

static int			wall_finder(t_data *img, double c, double angle, int j)
{
	double	xx;
	double	yy;

	img->structure->player_pos->xx = \
	img->structure->player_pos->x + c * cos(angle);
	img->structure->player_pos->yy = \
	img->structure->player_pos->y + c * sin(angle);
	xx = img->structure->player_pos->xx;
	yy = img->structure->player_pos->yy;
	if (img->structure->map[(int)yy][(int)xx] == '1' \
		|| img->structure->map[(int)yy][(int)xx] == '\0' \
		|| img->structure->map[(int)yy][(int)xx] == ' ')
	{
		img->wall_d[img->structure->win_w - j] = c;
		return (1);
	}
	return (0);
}

double			correctangle(double angle)
{
	if (angle >= 2 * M_PI)
		return (angle - 2 * M_PI);
	else if (angle < 0)
		return (angle + 2 * M_PI);
	return (angle);
}

void			epic_raycasting(double *c, double x, double y, double angle)
{
	double xx;
	double yy;
	double result;

	if ((angle > 0 && angle <= M_PI_2) || \
	(angle > 0 + 2 * M_PI && angle <= M_PI_2 + 2 * M_PI))
	{
		xx = (((int)x - x + 1) / cos(angle));
		yy = (((int)y - y + 1) / sin(angle));
	}
	else if (angle > M_PI_2 && angle < M_PI)
	{
		xx = (x - (int)x) / (cos(correctangle(angle)));
		yy = (((int)y - y + 1) / sin(angle));
	}
	else if (angle <= -M_PI_2 + 2 * M_PI && angle >= M_PI)
	{
		xx = (x - (int)x) / (cos(correctangle(angle)));
		yy = (y - (int)y) / (sin(correctangle(angle)));
	}
	else
	{
		xx = (((int)x - x + 1) / cos(angle));
		yy = (y - (int)y) / (sin(correctangle(angle)));
	}
	result = countres(xx, yy);
	*c = *c + result;
}

static void			print_3d(t_map *structure, t_data *img)
{
	double	c;
	int		j;
	double	angle;

	angle = structure->player_pos->player_facing - M_PI_2 / 3;
	j = 0;
	img->wall_d = malloc(sizeof(double) * img->structure->win_w);
	while (++j < structure->win_w)
	{
		angle = angle + (M_PI / 3) / structure->win_w;
		angle = correctangle(angle);
		c = 0.000001;
		while (!(wall_finder(img, c, angle, j)))
			epic_raycasting(&c, structure->player_pos->xx, \
			structure->player_pos->yy, angle);
		wall_painter(img, j - 1, c, angle);
	}
	wall_painter(img, structure->win_w - 1, c, angle);
	sprite_finder(img, structure->player_pos->player_facing - M_PI_2 / 3);
	free(img->wall_d);
}

static int			any_key(int keycode, t_data *img)
{
	if (keycode == 13 || keycode == 126)
	{
		if (img->structure->map[(int)(img->structure->player_pos->y + 0.2 * \
		sin(img->structure->player_pos->player_facing))]\
		[(int)(img->structure->player_pos->x + 0.2 * \
		cos(img->structure->player_pos->player_facing))] == '1' || \
		img->structure->map[(int)(img->structure->player_pos->y + 0.2 * \
		sin(img->structure->player_pos->player_facing))]\
		[(int)(img->structure->player_pos->x + 0.2 * \
		cos(img->structure->player_pos->player_facing))] == ' ' || \
		img->structure->map[(int)(img->structure->player_pos->y + 0.2 * \
		sin(img->structure->player_pos->player_facing))]\
		[(int)(img->structure->player_pos->x + 0.2 * \
		cos(img->structure->player_pos->player_facing))] == '\0')
			return (0);
		img->structure->player_pos->y += 0.2 * \
		sin(img->structure->player_pos->player_facing);
		img->structure->player_pos->x += 0.2 * \
		cos(img->structure->player_pos->player_facing);
		print_3d(img->structure, img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
		mlx_do_sync(img->mlx);
	}
	else if (keycode == 1 || keycode == 125)
	{
		if (img->structure->map[(int)(img->structure->player_pos->y + 0.1 * \
		sin(img->structure->player_pos->player_facing + M_PI))]\
		[(int)(img->structure->player_pos->x + 0.1 * \
		cos(img->structure->player_pos->player_facing + M_PI))] == '1' || \
		img->structure->map[(int)(img->structure->player_pos->y + 0.1 * \
		sin(img->structure->player_pos->player_facing + M_PI))]\
		[(int)(img->structure->player_pos->x + 0.1 * \
		cos(img->structure->player_pos->player_facing + M_PI))] == ' ' || \
		img->structure->map[(int)(img->structure->player_pos->y + 0.1 * \
		sin(img->structure->player_pos->player_facing + M_PI))]\
		[(int)(img->structure->player_pos->x + 0.1 * \
		cos(img->structure->player_pos->player_facing + M_PI))] == '\0')
			return (0);
		img->structure->player_pos->y += 0.1 * \
		sin(img->structure->player_pos->player_facing + M_PI);
		img->structure->player_pos->x += 0.1 * \
		cos(img->structure->player_pos->player_facing + M_PI);
		print_3d(img->structure, img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
		mlx_do_sync(img->mlx);
	}
	else if (keycode == 0)
	{
		if ((img->structure->map[(int)(img->structure->player_pos->y + 0.1 * \
		sin(img->structure->player_pos->player_facing - M_PI_2))]\
		[(int)(img->structure->player_pos->x + 0.1 * \
		cos(img->structure->player_pos->player_facing - M_PI_2))] == '1' || \
		img->structure->map[(int)(img->structure->player_pos->y + 0.1 * \
		sin(img->structure->player_pos->player_facing - M_PI_2))]\
		[(int)(img->structure->player_pos->x + 0.1 * \
		cos(img->structure->player_pos->player_facing - M_PI_2))] == '\0' || \
		img->structure->map[(int)(img->structure->player_pos->y + 0.1 * \
		sin(img->structure->player_pos->player_facing - M_PI_2))]\
		[(int)(img->structure->player_pos->x + 0.1 * \
		cos(img->structure->player_pos->player_facing - M_PI_2))] == ' ') || \
		(img->structure->map[(int)(img->structure->player_pos->y + 0.2 * \
		sin(img->structure->player_pos->player_facing - M_PI_2))]\
		[(int)(img->structure->player_pos->x + 0.2 * \
		cos(img->structure->player_pos->player_facing - M_PI_2))] == '1' || \
		img->structure->map[(int)(img->structure->player_pos->y + 0.2 * \
		sin(img->structure->player_pos->player_facing - M_PI_2))]\
		[(int)(img->structure->player_pos->x + 0.2 * \
		cos(img->structure->player_pos->player_facing - M_PI_2))] == '\0' || \
		img->structure->map[(int)(img->structure->player_pos->y + 0.2 * \
		sin(img->structure->player_pos->player_facing - M_PI_2))]\
		[(int)(img->structure->player_pos->x + 0.2 * \
		cos(img->structure->player_pos->player_facing - M_PI_2))] == ' '))
			return (0);
		img->structure->player_pos->y += 0.1 * \
		sin(img->structure->player_pos->player_facing - M_PI_2);
		img->structure->player_pos->x += 0.1 * \
		cos(img->structure->player_pos->player_facing - M_PI_2);
		print_3d(img->structure, img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
		mlx_do_sync(img->mlx);
	}
	else if (keycode == 2)
	{
		if (img->structure->map[(int)(img->structure->player_pos->y + 0.1 * \
		sin(img->structure->player_pos->player_facing + M_PI_2))]\
		[(int)(img->structure->player_pos->x + 0.1 * \
		cos(img->structure->player_pos->player_facing + M_PI_2))] == '1' || \
		img->structure->map[(int)(img->structure->player_pos->y + 0.1 * \
		sin(img->structure->player_pos->player_facing + M_PI_2))]\
		[(int)(img->structure->player_pos->x + 0.1 * \
		cos(img->structure->player_pos->player_facing + M_PI_2))] == '\0' || \
		img->structure->map[(int)(img->structure->player_pos->y + 0.1 * \
		sin(img->structure->player_pos->player_facing + M_PI_2))]\
		[(int)(img->structure->player_pos->x + 0.1 * \
		cos(img->structure->player_pos->player_facing + M_PI_2))] == ' ' || \
		img->structure->map[(int)(img->structure->player_pos->y + 0.2 * \
		sin(img->structure->player_pos->player_facing + M_PI_2))]\
		[(int)(img->structure->player_pos->x + 0.2 * \
		cos(img->structure->player_pos->player_facing + M_PI_2))] == '1' || \
		img->structure->map[(int)(img->structure->player_pos->y + 0.2 * \
		sin(img->structure->player_pos->player_facing + M_PI_2))]\
		[(int)(img->structure->player_pos->x + 0.2 * \
		cos(img->structure->player_pos->player_facing + M_PI_2))] == '\0' || \
		img->structure->map[(int)(img->structure->player_pos->y + 0.2 * \
		sin(img->structure->player_pos->player_facing + M_PI_2))]\
		[(int)(img->structure->player_pos->x + 0.2 * \
		cos(img->structure->player_pos->player_facing + M_PI_2))] == ' ')
			return (0);
		img->structure->player_pos->y += 0.1 * \
		sin(img->structure->player_pos->player_facing + M_PI_2);
		img->structure->player_pos->x += 0.1 * \
		cos(img->structure->player_pos->player_facing + M_PI_2);
		print_3d(img->structure, img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
		mlx_do_sync(img->mlx);
	}
	else if (keycode == 124)
	{
		img->structure->player_pos->player_facing = \
		correctangle(img->structure->player_pos->player_facing + 0.1);
		print_3d(img->structure, img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
		mlx_do_sync(img->mlx);
	}
	else if (keycode == 123)
	{
		img->structure->player_pos->player_facing = \
		correctangle(img->structure->player_pos->player_facing - 0.1);
		print_3d(img->structure, img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
		mlx_do_sync(img->mlx);
	}
	else if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		free(img->sprites);
		exit(0);
	}
	else
		;
	return (0);
}

int		ft_close(t_data *img)
{
	exit(0);
}

void				i_am_cub3d(t_map *structure)
{
	t_data		img;
	void		*mlx;
	void		*mlx_win;

	mlx = mlx_init();
	img.no_img = malloc(sizeof(t_xpm));
	img.so_img = malloc(sizeof(t_xpm));
	img.ea_img = malloc(sizeof(t_xpm));
	img.we_img = malloc(sizeof(t_xpm));
	img.sprite = malloc(sizeof(t_xpm));
	img.sprite->img = mlx_xpm_file_to_image(mlx, structure->sprite_path, \
	&img.sprite->w, &img.sprite->h);
	img.sprite->addr = mlx_get_data_addr(img.sprite->img, \
	&img.sprite->bits_per_pixel, &img.sprite->line_length, \
	&img.sprite->endian);
	img.sprite->name = 'S';
	img.no_img->img = mlx_xpm_file_to_image(mlx, structure->no_path, \
	&img.no_img->w, &img.no_img->h);
	img.no_img->name = 'n';
	img.no_img->addr = mlx_get_data_addr(img.no_img->img, \
	&img.no_img->bits_per_pixel, &img.no_img->line_length, \
	&img.no_img->endian);
	img.so_img->img = mlx_xpm_file_to_image(mlx, structure->so_path, \
	&img.so_img->w, &img.so_img->h);
	img.so_img->name = 's';
	img.ea_img->img = mlx_xpm_file_to_image(mlx, structure->ea_path, \
	&img.ea_img->w, &img.ea_img->h);
	img.we_img->img = mlx_xpm_file_to_image(mlx, structure->we_path, \
	&img.we_img->w, &img.we_img->h);
	img.we_img->name = 'w';
	img.so_img->addr = mlx_get_data_addr(img.so_img->img, \
	&img.so_img->bits_per_pixel, &img.so_img->line_length, \
	&img.so_img->endian);
	img.we_img->addr = mlx_get_data_addr(img.we_img->img, \
	&img.we_img->bits_per_pixel, &img.we_img->line_length, \
	&img.we_img->endian);
	img.ea_img->addr = mlx_get_data_addr(img.ea_img->img, \
	&img.ea_img->bits_per_pixel, &img.ea_img->line_length, \
	&img.ea_img->endian);
	img.ea_img->name = 'e';
	mlx_win = mlx_new_window(mlx, structure->win_w, structure->win_h, "cub3D");
	img.mlx = mlx;
	img.mlx_win = mlx_win;
	img.img = mlx_new_image(mlx, structure->win_w, structure->win_h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	img.structure = structure;
	if (!(img.sprites = malloc(sizeof(t_sprite) * img.structure->sprite_num)))
		printf("ne malloc\n");
	print_3d(structure, &img);
	if (structure->save == 1)
	{
		screenshot(&img);
		exit (0);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx_win, 17, 1L << 0, ft_close, &img);
	mlx_hook(mlx_win, 2, 1L << 0, any_key, &img);
	mlx_loop(mlx);
}
