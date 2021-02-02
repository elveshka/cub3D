/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 16:19:30 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/29 00:00:01 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <string.h>

typedef struct		s_player
{
	double			x;
	double			y;
	double			xx;
	double			yy;
	double			player_facing;
}					t_player;

typedef struct		s_sprite
{
	double			x;
	double			y;
	double			c;
	double			angle;
}					t_sprite;

typedef struct		s_xpm
{
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				w;
	int				h;
	void			*img;
	char			name;
}					t_xpm;

typedef struct		s_map
{
	long			win_w;
	long			win_h;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	char			*sprite_path;
	int				f_r;
	int				f_g;
	int				f_b;
	int				c_r;
	int				c_g;
	int				c_b;
	char			*map_in_line;
	t_player		*player_pos;
	char			**map;
	int				error;
	int				map_start;
	int				sprite_num;
	int				save;
}					t_map;

typedef struct		s_data
{
	void			*img;
	t_xpm			*no_img;
	t_xpm			*so_img;
	t_xpm			*we_img;
	t_xpm			*ea_img;
	t_xpm			*sprite;
	t_sprite		*sprites;
	double			*wall_d;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx;
	void			*mlx_win;
	t_map			*structure;
}					t_data;

void				i_am_structure_init(t_map *structure);
char				*i_am_map_parser(char *line, int fd);
int					i_am_map_reader(t_map *structure, char *map);
void				i_am_cub3d(t_map *structure);
int					create_trgb(int t, int r, int g, int b);
void				sprite_finder(t_data *img, double angle);
double				correctangle(double angle);
void				epic_raycasting(double *c, double x, \
					double y, double angle);
void				putsprite(t_data *img, int num);
void				screenshot(t_data *img);
int					parse_game_settings(t_map *structure, char *line);
int					parse_ceil(t_map *structure, char *line);
int					parse_floor(t_map *structure, char *line);
int					check_map_again(int fd, char *line);
void				no_img_init(void *mlx, t_data *img);
void				so_img_init(void *mlx, t_data *img);
void				we_img_init(void *mlx, t_data *img);
void				ea_img_init(void *mlx, t_data *img);
void				s_img_init(void *mlx, t_data *img);
int					map_validating(t_map *structure);
int					map_check(t_map *structure, int i, int j, int flag);
void				init_all(t_data *img, void **mlx, void **mlx_win);
int					step_forward(t_data *img);
int					step_backward(t_data *img);
int					step_left(t_data *img);
int					step_right(t_data *img);
void				wall_painter(t_data *img, int j, double c, double angle);
int					get_color(t_xpm *img, int x, int y);
void				pixel_put(t_data *img, int x, int y, int color);
void				print_3d(t_map *structure, t_data *img);
int					ft_close(void);
void				sprite_painter(t_data *img, int num);
void				clear_sprites(t_data *img);
double				correctangle2(double angle, double player_facing);
void				check_resolution(t_data *img);
int					check_map_name(char *str);

#endif
