/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:18:44 by osarsari          #+#    #+#             */
/*   Updated: 2024/03/12 11:39:00 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

# include "../mlx/mlx.h"

// Screen resolution
# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 768

// HARDCODED COLORS
# define CEIL_COLOR 0x87CEEB
# define FLOOR_COLOR 0x228B22
# define WALL_COLOR 0x8B4513

// Keycodes
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

// Image structure
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

// Point structure
typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

// Bresenham structure
typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}		t_bresenham;

// Pixel structure
typedef struct s_pixel
{
	int	x;
	int	y;
	int	color;
}		t_pixel;

// Player structure
typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	ms;
	double	rs;
}			t_player;

// Camera structure
typedef struct s_camera
{
	double	x;
	double	plane_x;
	double	plane_y;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}			t_camera;

// Game structure
typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			**map;
	t_img		*img;
	t_player	*player;
	t_camera	*camera;
}				t_game;

// Utils
double	deg_to_rad(double deg);
int		rgb_to_int(int r, int g, int b);
void	draw_pixel(t_img *img, t_pixel *pixel);
void	draw_bg(t_img *img, int ceil, int floor);
void	draw_line(t_img *img, t_point *p0, t_point *p1, int color);
void	esc(t_game *game, int status);

// Raycasting
void	ray_cast(t_game *game);

// Movement
void	move_w_s(t_player *player, int **map, int keycode);
// void	move_backward(t_player *player, int **map);
void	move_a_d(t_player *player, int **map, int keycode);
// void	move_right(t_player *player, int **map);
void	rotate(t_player *player, t_camera *camera, int keycode);
// void	rotate_left(t_player *player, t_camera *camera);
// void	rotate_right(t_player *player, t_camera *camera);

// Key hooks
int		key_press(int keycode, t_game *game);

#endif